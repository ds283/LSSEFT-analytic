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

#ifndef LSSEFT_ANALYTIC_RAYLEIGH_DB_H
#define LSSEFT_ANALYTIC_RAYLEIGH_DB_H


#include <map>
#include <vector>

#include "utilities/GiNaC_utils.h"


//! Rayleigh_db is a class that keeps track of assignments of Rayleigh momenta
//! It can also match expressions to Rayleigh momenta, possibly modulo constraints.
//! This is necessary so that, say, k1 + l1 and l1 - k2 get matched to the same
//! Rayleigh momentum in a 2pf with momentum conservation where k1 + k2 = 0.
class Rayleigh_db
  {

    // TYPES

  protected:

    //! main database type is a map from a GiNaC symbol (the Rayleigh momentum) to a GiNaC expression
    using db_type = std::map<GiNaC::symbol, GiNaC::ex>;

    //! constraint database is a list of constraints c_i that are taken to equal zero, c_i = 0
    using constraint_db_type = std::vector<GiNaC::ex>;

  public:

    //! const iterator
    using const_iterator = db_type::const_iterator;

    //! const reverse iterator
    using const_reverse_iterator = db_type::const_reverse_iterator;


    // CONSTRUCTOR, DESTRUCTOR

  public:

    //! constructor is default
    Rayleigh_db() = default;

    //! destructor is default
    ~Rayleigh_db() = default;


    // ITERATORS

  public:

    //! begin iterator
    const_iterator begin() const { return this->db.cbegin(); }

    //! const begin iterator
    const_iterator cbegin() const { return this->db.cbegin(); }

    //! reverse begin iterator
    const_reverse_iterator rbegin() const { return this->db.rbegin(); }

    //! const reverse begin iterator
    const_reverse_iterator crbegin() const { return this->db.crbegin(); }

    //! end iterator
    const_iterator end() const { return this->db.cend(); }

    //! const end iterator
    const_iterator cend() const { return this->db.cend(); }

    //! reverse end iterator
    const_reverse_iterator rend() const { return this->db.rend(); }

    //! const reverse end iterator
    const_reverse_iterator crend() const { return this->db.crend(); }


    // EMPLACE

  public:

    //! emplace a new Rayleigh momentum.
    //! returns an iterator to the newly emplaced object, or to an existing object with the same
    //! symbol, if one exists
    const_iterator emplace(GiNaC::symbol key, GiNaC::ex expr);


    // SEARCH

  public:

    //! find the record for a given symbol
    const_iterator find(const GiNaC::symbol& key) const;

    //! reverse lookup: find a symbol for a given expression (possibly using constraints to generate
    //! equivalence classes)
    const_iterator reverse_find(const GiNaC::ex& expr) const;


    // CONSTRAINTS

  public:

    //! add a constraint.
    //! constraints are considered when performing reverse-lookup to match expression to Rayleigh momenta
    //! The constraint is given as a GiNaC expression that is taken to be identically zero, c = 0.
    Rayleigh_db& add_constraint(GiNaC::ex c);


    // SERVICES

  public:

    //! prune the database using a given expression as a reference.
    //! rules that are not used in the reference expression are removed from the database
    void prune(const GiNaC::ex& ref);

  protected:

    //! test whether a given expression is zero modulo the constraints
    bool zero_mod_constraints(const GiNaC::ex expr) const;


    // INTERNAL DATA

  private:

    //! main database
    db_type db;

    //! constraint database
    constraint_db_type constraint_db;

  };


#endif //LSSEFT_ANALYTIC_RAYLEIGH_DB_H
