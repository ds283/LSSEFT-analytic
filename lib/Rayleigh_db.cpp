//
// Created by David Seery on 08/04/2018.
// --@@
// Copyright (c) 2018 University of Sussex. All rights reserved.
//
// This file is part of the Sussex Effective Field Theory for
// Large-Scale Structure analytic calculation platform (LSSEFT-analytic).
//
// LSSEFT-analytic is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// LSSEFT-analytic is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LSSEFT-analytic.  If not, see <http://www.gnu.org/licenses/>.
//
// @license: GPL-2
// @contributor: David Seery <D.Seery@sussex.ac.uk>
// --@@
//

#include <string>
#include <sstream>
#include <algorithm>

#include "Rayleigh_db.h"

#include "utilities/GiNaC_utils.h"

#include "localizations/messages.h"
#include "shared/exceptions.h"


Rayleigh_db::const_iterator Rayleigh_db::emplace(GiNaC::symbol key, GiNaC::ex expr)
  {
    // check whether a Rayleigh momentum with this label is already present
    auto t = this->db.find(key);
    if(t != this->db.end())
      {
        std::ostringstream msg;
        msg << ERROR_RAYLEIGH_DATABASE_KEY_ALREADY_PRESENT << " " << key << " -> " << expr;
        throw exception(msg.str(), exception_code::Rayleigh_error);
      }

    // emplace new rule in database, check that insertion occurred, and return iterator to element
    auto res = this->db.emplace(std::move(key), std::move(expr));
    if(!res.second) throw exception(ERROR_RAYLEIGH_DATABASE_INSERT_FAILED, exception_code::Rayleigh_error);

    return res.first;
  }


Rayleigh_db::const_iterator Rayleigh_db::find(const GiNaC::symbol& key) const
  {
    // pass find request directly through to underlying database
    return this->db.find(key);
  }


Rayleigh_db::const_iterator Rayleigh_db::reverse_find(const GiNaC::ex& expr) const
  {
    // step through the database, checking whether any of the mapped expressions agree with our
    // quoted expression, modulo the constraints

    auto t = this->db.begin();
    for(; t != this->db.end(); ++t)
      {
        if(this->zero_mod_constraints(t->second-expr) || this->zero_mod_constraints(t->second+expr))
          break;
      }

    return t;
  }


Rayleigh_db& Rayleigh_db::add_constraint(GiNaC::ex c)
  {
    // determine whether the constraint is already linearly related to any (subset of) constraints already emplaced
    if(this->zero_mod_constraints(c)) return;

    this->constraint_db.emplace_back(std::move(c));
  }


void Rayleigh_db::prune(const GiNaC::ex& ref)
  {
    // get symbols used in reference expression
    const auto& symbols = get_expr_symbols(ref);

    // step through rule database, removing replacement rules for symbols that no longer occur in K
    for(auto t = this->db.begin(); t != this->db.end(); /* intentionally left blank*/)
      {
        const auto& sym = GiNaC::ex_to<GiNaC::symbol>(t->first);

        // if symbol occurs in the reference expression, move on
        if(symbols.find(sym) != symbols.end())
          {
            ++t;
            continue;
          }

        // otherwise, symbol did not occur so can be pruned.
        // remove this replacement rule
        t = this->db.erase(t);
      }
  }


bool Rayleigh_db::zero_mod_constraints(const GiNaC::ex expr) const
  {
    // currently a dumb implementation, just checks whether a single constraint works

    // return true if expr is identically zero even without constraints
    if(static_cast<bool>(expr == 0)) return true;

    // work through constraints one at a time, checking whether they make expr zero
    for(const auto& c : this->constraint_db)
      {
        if(static_cast<bool>(expr+c == 0) || static_cast<bool>(expr-c == 0)) return true;
      }

    return false;
  }


GiNaC_symbol_set Rayleigh_db::get_Rayleigh_labels() const
  {
    GiNaC_symbol_set syms;

    for(const auto& item : this->db)
      {
        syms.insert(item.first);
      }

    return syms;
  }


GiNaC::exmap Rayleigh_db::prune_trivial()
  {
    // set up exmap that will contain replacement rules taking the place of any trivial Rayleigh rules
    GiNaC::exmap rules;

    // loop through all rules
    for(auto t = this->db.begin(); t != this->db.end(); /* deliberately left empty */)
      {
        // get RHS of this tule
        const GiNaC::ex& rhs = t->second;

        // if trivially just a single symbol, add replacement rule and erase
        if(GiNaC::is_a<GiNaC::symbol>(rhs))
          {
            rules.emplace(t->first, t->second);
            t = this->db.erase(t);
            continue;
          }

        // alternatively, if just a numerical factor multiplied by a symbol, also perform replacement
        if(GiNaC::is_a<GiNaC::mul>(rhs) && rhs.nops() == 2)
          {
            const auto& rhs_mul = GiNaC::ex_to<GiNaC::mul>(rhs);
            const GiNaC::ex op1 = rhs_mul.op(0);
            const GiNaC::ex op2 = rhs_mul.op(1);

            if((GiNaC::is_a<GiNaC::symbol>(op1) && GiNaC::is_a<GiNaC::numeric>(op2))
               || (GiNaC::is_a<GiNaC::symbol>(op2) && GiNaC::is_a<GiNaC::numeric>(op1)))
              {
                rules.emplace(t->first, t->second);
                t = this->db.erase(t);
                continue;
              }
          }

        // no reason to prune this entry, so move on
        ++t;
      }

    return rules;
  }


GiNaC::exmap
Rayleigh_db::merge(const Rayleigh_db& source, const GiNaC_symbol_set& reserved, const GiNaC::exmap& subs_rules,
                   bool merge_constraints)
  {
    // empty relabelling rules, to be applied to expressions associated with the incoming database
    GiNaC::exmap remap_rules;

    // get reference to symbol factory
    auto& sf = this->loc.get_symbol_factory();

    // if merging of constraints is not disabled, copy constraints from 2nd database into our own list
    if(merge_constraints)
      {
        for(const auto& item : source.constraint_db)
          {
            this->add_constraint(item);
          }
      }

    // check whether any of the substitution rules in 'source' already exist in our database, subject
    // to the constraints we are currently holding
    for(const auto& rule : source.db)
      {
        GiNaC::symbol label = rule.first;
        const GiNaC::ex& value = rule.second.subs(subs_rules);

        // drop any rules that evalulate to zero
        if(this->zero_mod_constraints(value)) continue;

        // search for an existing rule with the same right-hand side
        auto t = this->reverse_find(value);

        // if an existing rule can be found, then we need a remap rule for any expressions associated with the
        // incoming database. They will need to be relabelled to use our version of the rule.
        if(t != this->db.end())
          {
            remap_rules[label] = t->first;
            continue;
          }

        // otherwise, there is no existing rule, so we should copy it over

        // determine whether there is a symbol collision
        bool collision = false;
        if(reserved.find(label) != reserved.end()) collision = true;
        if(this->db.find(label) != this->db.end()) collision = true;

        // if there is a collision, we should assign a new, unique label and add a remap rule for it
        if(collision)
          {
            auto old_label = label;
            label = sf.make_unique_Rayleigh_momentum();
            remap_rules[old_label] = label;
          }

        this->emplace(label, value);
      }

    return remap_rules;
  }


GiNaC::exmap Rayleigh_db::merge_and_update_reserved(const Rayleigh_db& source, const GiNaC_symbol_set& reserved,
                                                    const GiNaC::exmap& subs_rules, bool merge_constraints)
  {
    auto remap_rules = this->merge(source, reserved, subs_rules, merge_constraints);

    const auto source_set = source.get_Rayleigh_labels();
    const auto dest_set = this->get_Rayleigh_labels();

    std::copy(source_set.begin(), source_set.end(), std::inserter(reserved, reserved.end()));
    std::copy(dest_set.begin(), dest_set.end(), std::inserter(reserved, reserved.end()));

    return remap_rules;
  }
