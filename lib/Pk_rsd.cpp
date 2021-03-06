//
// Created by David Seery on 11/09/2017.
// --@@
// Copyright (c) 2017 University of Sussex. All rights reserved.
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

#include <algorithm>

#include "Pk_rsd.h"


Pk_rsd_group::Pk_rsd_group(GiNaC::symbol mu_, filter_list pt_, GiNaC_symbol_set sy_, std::string nm_, bool v)
  : name(std::move(nm_)),
    mu(std::move(mu_)),
    pattern(std::move(pt_)),
    filter_symbols(std::move(sy_)),
    symbolic_filter(1),
    verbose(v)
  {
    // set up an exmap that will set all filter_symbols to zero; we use this after pattern matching
    // to kill any remaining terms; eg. asking for the term linear in b1 from b1(1+b2) will give 1+b2, and we
    // need to set b2 to zero to get the required result '1'
    for(const auto& sym : filter_symbols)
      {
        filter_map[sym] = 0;
      }

    // build up GiNaC expression representing filter symbol string
    for(const auto& item : pattern)
      {
        symbolic_filter *= GiNaC::pow(item.first, item.second);
      }
  }


void Pk_rsd_group::emplace(const one_loop_element& elt)
  {
    auto filter = [&](const auto& e, unsigned int order) -> auto
      {
        // copy input element; one_loop_element doesn't capture any of its data by reference,
        // so what we get is a standalone copy.
        // That means we can later modify the Pk_one_loop object if we require, without
        // changing what is stored here
        auto f = std::make_unique<one_loop_element>(e);

        // filter for pattern; note that this assumes the pattern symbols are all in the integrand,
        // and none in the time function (which is certainly the intention, but things could go wrong
        // if somehow not all symbols are normalized out of the time function)
        for(const auto& pat : this->pattern)
          {
            f->filter(pat.first, pat.second);
          }

        // kill any remaining symbols (eg. if we are looking for the term linear in b1 we don't get b1 b2 contributions)
        f->simplify(this->filter_map);

        // filter for power of mu
        f->filter(this->mu, order);

        return f;
      };

    this->emplace(filter(elt, 0), this->mu0, 0);
    this->emplace(filter(elt, 2), this->mu2, 2);
    this->emplace(filter(elt, 4), this->mu4, 4);
    this->emplace(filter(elt, 6), this->mu6, 6);
    this->emplace(filter(elt, 8), this->mu8, 8);
  }


GiNaC::exvector Pk_rsd_group::get_UV_limit(unsigned int order) const
  {
    GiNaC::exvector values;

    auto build = [&](const one_loop_element_db& db) -> auto
      {
        GiNaC::ex value{0};

        for(const auto& record : db)
          {
            const auto& data = record.second;

            if(data) value += data->get_UV_limit(order);
          }

        return value;
      };

    values.push_back(build(this->mu0));
    values.push_back(build(this->mu2));
    values.push_back(build(this->mu4));
    values.push_back(build(this->mu6));
    values.push_back(build(this->mu8));

    return values;
  }


void Pk_rsd_group::write(std::ostream& out) const
  {
    out << "-- mu^0" << '\n'; if(!this->mu0.empty()) out << this->mu0 << '\n'; else out << "   <empty>" << '\n';
    out << "-- mu^2" << '\n'; if(!this->mu2.empty()) out << this->mu2 << '\n'; else out << "   <empty>" << '\n';
    out << "-- mu^4" << '\n'; if(!this->mu4.empty()) out << this->mu4 << '\n'; else out << "   <empty>" << '\n';
    out << "-- mu^6" << '\n'; if(!this->mu6.empty()) out << this->mu6 << '\n'; else out << "   <empty>" << '\n';
    out << "-- mu^8" << '\n'; if(!this->mu8.empty()) out << this->mu8 << '\n'; else out << "   <empty>" << '\n';
  }


std::vector< std::vector<time_function> > Pk_rsd_group::get_time_functions() const
  {
    std::vector< std::vector<time_function> > values(5);

    auto build = [](const one_loop_element_db& db, std::vector<time_function>& dest)
      {
        for(const auto& item : db)
          {
            const GiNaC::ex& tm = item.first.get_time_function();

            auto it = std::find_if(dest.begin(), dest.end(),
                                   [&](const time_function& t) -> bool
                                     { return static_cast<bool>(t == tm); });

            if(it == dest.end()) dest.push_back(tm);
          }
      };

    build(this->mu0, values[0]);
    build(this->mu2, values[1]);
    build(this->mu4, values[2]);
    build(this->mu6, values[3]);
    build(this->mu8, values[4]);

    return values;
  }


void Pk_rsd_group::prune()
  {
    this->prune(this->mu0, 0);
    this->prune(this->mu2, 2);
    this->prune(this->mu4, 4);
    this->prune(this->mu6, 6);
    this->prune(this->mu8, 8);
  }


void Pk_rsd_group::prune(one_loop_element_db& db, unsigned int mu_power)
  {
    auto t = db.begin();

    while(t != db.end())
      {
        const one_loop_element& elt = *t->second;
        if(elt.null())
          {
            if(this->verbose)
              {
                std::cout << "Pruning '" << this->name << "' Pk_rsd_group contribution for filter pattern '"
                          << this->symbolic_filter << "' at mu^" << mu_power << '\n';
                std::cout << elt << '\n';
              }
            t = db.erase(t);
          }
        else
          {
            ++t;
          }
      }
  }


void Pk_rsd_group::emplace(std::unique_ptr<one_loop_element> elt, one_loop_element_db& db, unsigned int mu_power)
  {
    // nothing to do if element is empty
    if(elt->null()) return;

    if(this->verbose)
      {
        std::cout << "Storing '" << this->name << "' Pk_rsd_group contribution for filter pattern '"
                  << this->symbolic_filter << "' at mu^" << mu_power << '\n';
        std::cout << *elt << '\n';
      }

    one_loop_element_key key{*elt};

    // check whether a compatible entry is already present in the database
    auto it = db.find(key);

    // if such an entry is present we can just compose the integrands
    if(it != db.end())
      {
        *it->second += *elt;
        return;
      }

    // otherwise, we need to insert a new element
    auto res = db.emplace(std::move(key), std::move(elt));
    if(!res.second) throw exception(ERROR_ONE_LOOP_ELEMENT_INSERT_FAILED_RSD, exception_code::loop_integral_error);
  }


void Pk_rsd_group::write_Mathematica(std::ostream& out, std::string symbol, bool do_dx) const
  {
    this->write_Mathematica_block(out, this->mu0, symbol, "mu0", do_dx);
    this->write_Mathematica_block(out, this->mu2, symbol, "mu2", do_dx);
    this->write_Mathematica_block(out, this->mu4, symbol, "mu4", do_dx);
    this->write_Mathematica_block(out, this->mu6, symbol, "mu6", do_dx);
    this->write_Mathematica_block(out, this->mu8, symbol, "mu8", do_dx);
  }


void Pk_rsd_group::write_Mathematica_block(std::ostream& out, const one_loop_element_db& db, std::string symbol,
                                           std::string label, bool do_dx) const
  {
    out << symbol << "z" << label << " = ";

    unsigned int count = 0;
    size_t chars_written = 0;

    for(auto& record : db)
      {
        const std::unique_ptr<one_loop_element>& elt = record.second;

        if(count > 0) out << " + ";

        auto output = elt->to_Mathematica(do_dx);
        out << output;

        ++count;
        chars_written += output.length();
      }

    if(chars_written == 0) out << "0";

    out << ";" << '\n';
  }


Pk_rsd::Pk_rsd(const Pk_one_loop& Pk, const GiNaC::symbol& mu_,
               const filter_list pt_, const GiNaC_symbol_set sy_, bool v)
  : mu(mu_),
    pattern(pt_),
    Ptree(mu_, pt_, sy_, std::string{"tree"}, v),
    P13(mu_, pt_, sy_, std::string{"13"}, v),
    P22(mu_, pt_, sy_, std::string{"22"}, v),
    symbolic_filter(1)
  {
    // build tag from filter list
    std::ostringstream tag_str;
    tag_str << Pk.get_tag();

    for(const auto& sym : pt_)
      {
        // remove occurrences of '_' in symbol name, since these aren't legal in Mathematica symbols
        // and we use the tag for that purpose
        std::string name = sym.first.get_name();
        std::replace(name.begin(), name.end(), '_', 'z');

        for(unsigned int i = 0; i < sym.second; ++i)
          {
            tag_str << "z" << name;
          }
      }

    tag = tag_str.str();

    // build up symbolic representation of filter pattern
    for(const auto& item : pattern)
      {
        symbolic_filter *= GiNaC::pow(item.first, item.second);
      }

    // filter elements (term by term) from parent Pk_one_loop according to whether they match
    // the specific symbol set
    this->filter(Ptree, Pk.get_tree());
    this->filter(P13, Pk.get_13());
    this->filter(P22, Pk.get_22());

    // remove empty records
    this->Ptree.prune();
    this->P13.prune();
    this->P22.prune();

    error_handler err;
    if(this->Ptree.empty() && this->P13.empty() && this->P22.empty())
      {
        std::ostringstream msg;
        msg << WARNING_PK_RSD_EMPTY << " '" << this->symbolic_filter << "'";
        err.warn(msg.str());
      }
  }


void Pk_rsd::filter(Pk_rsd_group& dest, const Pk_one_loop_impl::Pk_db& source)
  {
    // walk through the source Pk_db, filtering contributions to the reduced integral (if present)
    // that match our configured symbol set
    // Matching contributions get pushed into the destination database 'dest',
    // which will be either tree, 13 or 22

    for(const auto& item : source)
      {
        const loop_integral& lp = *item.second.first;
        const std::unique_ptr<one_loop_reduced_integral>& ri = item.second.second;

        if(!ri) continue;    // skip if pointer is empty

        // get database of one-loop-reduced-integral elements
        const auto& db  = ri->get_db();

        // walk through this list
        for(const auto& record : db)
          {
            const std::unique_ptr<one_loop_element>& elt = record.second;
            if(elt) dest.emplace(*elt);
          }
      }
  }


void Pk_rsd::write(std::ostream& out) const
  {
    out << "Tree-level:" << '\n';
    out << this->Ptree << '\n';
    out << "Loop-level 13 terms:" << '\n';
    out << this->P13 << '\n';
    out << "Loop-level 22 terms:" << '\n';
    out << this->P22 << '\n';
  }


void Pk_rsd::write_Mathematica(std::ostream& out) const
  {
    this->Ptree.write_Mathematica(out, this->tag + "Tree", false);
    this->P13.write_Mathematica(out, this->tag + "P13", true);
    this->P22.write_Mathematica(out, this->tag + "P22", false);
  }


std::ostream& operator<<(std::ostream& str, const Pk_rsd& obj)
  {
    obj.write(str);
    return str;
  }


std::ostream& operator<<(std::ostream& str, const Pk_rsd_group& obj)
  {
    obj.write(str);
    return str;
  }
