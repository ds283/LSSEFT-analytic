//
// Created by David Seery on 21/08/2017.
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

#ifndef LSSEFT_ANALYTIC_EXCEPTIONS_H
#define LSSEFT_ANALYTIC_EXCEPTIONS_H


#include <string>
#include <stdexcept>


enum class exception_code
  {
    symbol_error,
    kernel_error,
    initial_value_error,
    contraction_error,
    index_error,
    Rayleigh_error,
    Pk_error,
    loop_integral_error,
    loop_transformation_error,
    Fabrikant_error,
    backend_error
  };


class exception: public std::runtime_error
  {
    
    // CONSTRUCTOR, DESTRUCTOR
    
  public:
    
    //! constructor
    exception(std::string msg, exception_code c);
    
    //! destructor
    ~exception() override = default;
    
    
    // INTERFACE
    
  public:
    
    //! read exception code
    exception_code get_code() const { return this->code; }
    
    
    // INTERNAL DATA
    
  private:
    
    //! cache exception code
    exception_code code;
  
  };


#endif //LSSEFT_ANALYTIC_EXCEPTIONS_H
