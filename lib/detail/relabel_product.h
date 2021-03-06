//
// Created by David Seery on 29/08/2017.
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

#ifndef LSSEFT_ANALYTIC_RELABEL_PRODUCT_H
#define LSSEFT_ANALYTIC_RELABEL_PRODUCT_H


#include "services/service_locator.h"
#include "utilities/GiNaC_utils.h"


namespace detail
  {
    
    //! relabel indices in a product
    GiNaC::ex relabel_index_product(const GiNaC::ex& a, const GiNaC::ex& b, service_locator& loc);
    
  }   // namespace detail


#endif //LSSEFT_ANALYTIC_RELABEL_PRODUCT_H
