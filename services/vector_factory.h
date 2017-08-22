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

#ifndef LSSEFT_ANALYTIC_VECTOR_FACTORY_H
#define LSSEFT_ANALYTIC_VECTOR_FACTORY_H


#include "symbol_factory.h"


//! vector_factory provides a unified API for handling symbols that are vectors
class vector_factory
  {
    
    // CONSTRUCTOR, DESTRUCTOR
    
  public:
    
    //! constructor captures a symbol_factory instance
    explicit vector_factory(symbol_factory& f);
    
    //! destructor is default
    ~vector_factory() = default;
    
    
    // INTERNAL DATA
    
  private:
    
    //! reference to symbol factory instance
    symbol_factory factory;
  
  };


#endif //LSSEFT_ANALYTIC_VECTOR_FACTORY_H
