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

#include "Rayleigh_db.h"

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
    // get symbols used in reference exprssion
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
    if(static_cast<bool>(expr == 0)) return true;

    for(const auto& c : this->constraint_db)
      {
        if(static_cast<bool>(expr+c == 0) || static_cast<bool>(expr-c == 0)) return true;
      }

    return false;
  }
