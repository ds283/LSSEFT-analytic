//
// Created by David Seery on 22/08/2017.
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

#ifndef LSSEFT_ANALYTIC_GINAC_UTILS_H
#define LSSEFT_ANALYTIC_GINAC_UTILS_H


#include <set>

#include "ginac/ginac.h"


namespace std
  {
    
    //! specialize std::less for a GiNaC symbol, defined to
    //! order lexically by name
    template <>
    struct less<GiNaC::symbol>
      {
        bool operator()(const GiNaC::symbol& a, const GiNaC::symbol& b) const
          {
            return a.get_name() < b.get_name();
          }
      };
    
  }   // namespace std


// forward-declare service locator
class service_locator;


//! set of GiNaC symbols, with comparison performed lexicographically by name
//! (GiNaC does not provide this option itself)
using GiNaC_symbol_set = std::set< GiNaC::symbol, std::less<GiNaC::symbol> >;


//! extract a set of GiNaC symbols from a given expression
GiNaC_symbol_set get_expr_symbols(const GiNaC::ex& expr);

//! extract a set of GiNaC indices from a given expression
//! only counts indices that occur >= min_occurrences times
GiNaC_symbol_set get_expr_indices(const GiNaC::ex& expr, size_t min_occurrences=0);

//! GiNaC's internal simplify_indexed() is broken, because it does not handle
//! index sums in the denominator or as the argument of powers with exponent other than +2
//! This is an alternative implementation that handles such cases
GiNaC::ex simplify_index(const GiNaC::ex& expr, const GiNaC::scalar_products& sp, const GiNaC::exmap& Rayleigh_list,
                         service_locator& loc);

//! version of simplify_index() without scalar_products table
GiNaC::ex simplify_index(const GiNaC::ex& expr, const GiNaC::exmap& Rayleigh_list, service_locator& loc);

//! GiNaC's internal is_rational() is broken, because it does not handle
//! indexed quantities
bool is_rational(const GiNaC::ex& expr);

//! convert a product to an expression vector
GiNaC::exvector to_exvector(const GiNaC::ex& expr);

//! order a set of symbols
std::vector<GiNaC::symbol> order_symbol_set(const GiNaC_symbol_set& syms);

#endif //LSSEFT_ANALYTIC_GINAC_UTILS_H
