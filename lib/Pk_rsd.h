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

#ifndef LSSEFT_ANALYTIC_PK_RSD_H
#define LSSEFT_ANALYTIC_PK_RSD_H


#include <iostream>
#include <set>

#include "Pk_one_loop.h"


using filter_list = std::vector< std::pair< GiNaC::symbol, unsigned int > >;


class Pk_rsd_group
  {

    // TYPES

    //! specify which mu powers to include in visitor pattern
    using visit_list = std::set<unsigned int>;


    // CONSTRUCTOR, DESTRUCTOR

  public:

    //! constructor
    Pk_rsd_group(GiNaC::symbol mu_, filter_list pt_, GiNaC_symbol_set sy_, std::string nm_, bool v);

    //! destructor
    ~Pk_rsd_group() = default;


    // EMPLACE TERMS

  public:

    //! accepts a one_loop_element and breaks it into individual powers of mu
    void emplace(const one_loop_element& elt);

  protected:

    //! perform emplace on a specific database (ie. the database for mu0, mu2, ...)
    void emplace(std::unique_ptr<one_loop_element> elt, one_loop_element_db& db, unsigned int mu_power);


    // TOOLS

  public:

    //! construct UV limit
    GiNaC::exvector get_UV_limit(unsigned int order=2) const;

    //! query number of distinct time functions at each mu
    std::vector< std::vector<time_function> > get_time_functions() const;

    //! prune empty records from the database
    void prune();

    //! determine whether empty
    bool empty() const
      { return this->mu0.empty() && this->mu2.empty() && this->mu4.empty() && this->mu6.empty() && this->mu8.empty(); }

  protected:

    //! prune the database for a specific power of mu
    void prune(one_loop_element_db& db, unsigned int mu_power);


    // SERVICES

  public:

    //! write self to stream
    void write(std::ostream& out) const;

    //! write Mathematica script for each power of mu
    void write_Mathematica(std::ostream& out, std::string symbol, bool do_dx) const;

    //! apply visitor to the one-loop records for any given pattern of mus
    template <typename VisitorFunction>
    void visit(visit_list pattern, VisitorFunction f) const;

  private:

    //! write Mathematica script for a specific mu database
    void write_Mathematica_block(std::ostream& out, const one_loop_element_db& db, std::string symbol,
                                 std::string label, bool do_dx) const;


    // INTERNAL DATA

  private:

    //! group name (tree, 13, 22)
    const std::string name;

    //! cache reference to angular variable mu
    const GiNaC::symbol mu;

    //! cache filtering pattern
    const filter_list pattern;

    //! GiNaC expression representing filter pattern
    GiNaC::ex symbolic_filter;

    //! set of filtering symbols (used to kill any leftover terms)
    const GiNaC_symbol_set filter_symbols;

    //! exmap build from these symbols
    GiNaC::exmap filter_map;

    //! verbose flag
    bool verbose;


    // TERM-BY-TERM DATABASES

    //! mu^0 terms
    one_loop_element_db mu0;

    //! mu^2 terms
    one_loop_element_db mu2;

    //! mu^4 terms
    one_loop_element_db mu4;

    //! mu^6 terms
    one_loop_element_db mu6;

    //! mu^8 terms;
    one_loop_element_db mu8;

  };


//! stream insertion
std::ostream& operator<<(std::ostream& str, const Pk_rsd_group& obj);


template <typename VisitorFunction>
void Pk_rsd_group::visit(visit_list pattern, VisitorFunction f) const
  {
    auto t0 = pattern.find(0);
    auto t2 = pattern.find(2);
    auto t4 = pattern.find(4);
    auto t6 = pattern.find(6);
    auto t8 = pattern.find(8);

    auto visit = [&](const one_loop_element_db& db) -> void
      {
        for(const auto& item : db)
          {
            const one_loop_element& elt = *item.second;
            f(elt);
          }
      };

    if(t0 != pattern.end()) visit(this->mu0);
    if(t2 != pattern.end()) visit(this->mu2);
    if(t4 != pattern.end()) visit(this->mu4);
    if(t6 != pattern.end()) visit(this->mu6);
    if(t8 != pattern.end()) visit(this->mu8);
  }


class Pk_rsd
  {

    // CONSTRUCTOR, DESTRUCTOR

  public:

    //! constructor accepts a Pk_one_loop and decomposes it into powers of mu.
    //! filters terms according to the provided pattern
    Pk_rsd(const Pk_one_loop& Pk, const GiNaC::symbol& mu_, const filter_list pt_, const GiNaC_symbol_set sy_,
           bool v=false);

    //! destructor is default
    ~Pk_rsd() = default;


    // INTERNAL API

  protected:

    //! filter a Pk_db into a destination Pk_rsd_group
    void filter(Pk_rsd_group& dest, const Pk_one_loop_impl::Pk_db& source);


    // ACCESSORS

  public:

    //! get tree-level terms
    const Pk_rsd_group& get_tree() const { return this->Ptree; }

    //! get 13 terms
    const Pk_rsd_group& get_13() const { return this->P13; }

    //! get 22 terms
    const Pk_rsd_group& get_22() const { return this->P22; }


    // SERVICES

  public:

    //! write self to stream
    void write(std::ostream& out) const;

    //! write Mathematica script for 13 and 22 integrals at each power of mu
    void write_Mathematica(std::ostream& out) const;


    // INTERNAL DATA

  private:

    //! cache mu parameter
    const GiNaC::symbol mu;

    //! cache tag used to represent this power spectrum group
    std::string tag;


    // FILTER/PATTERN

    //! cache pattern used to filter input expression
    const filter_list pattern;

    //! cache GiNaC expression giving symbolic filter list
    GiNaC::ex symbolic_filter;


    // DATABASES

    //! tree contributions
    Pk_rsd_group Ptree;

    //! 13 contributions
    Pk_rsd_group P13;

    //! 22 contributions
    Pk_rsd_group P22;

  };


//! stream insertion operator
std::ostream& operator<<(std::ostream& str, const Pk_rsd& obj);


#endif //LSSEFT_ANALYTIC_PK_RSD_H
