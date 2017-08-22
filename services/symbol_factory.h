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

#ifndef LSSEFT_ANALYTIC_SYMBOL_FACTORY_H
#define LSSEFT_ANALYTIC_SYMBOL_FACTORY_H


#include <map>
#include <memory>

#include "boost/optional.hpp"

#include "ginac/ginac.h"


//! symbol factory provides a unified API for building GiNaC symbols
class symbol_factory
  {
    
    // TYPES
    
  protected:
    
    //! type for database key
    using key_type = std::pair< std::string, boost::optional<std::string> >;
    
    //! type for symbol database
    using symbol_db = std::map< key_type, std::unique_ptr<GiNaC::symbol> >;
    
    
    // CONSTRUCTOR, DESTRUCTOR
    
  public:
    
    //! constructor is default
    symbol_factory() = default;
    
    //! destructor is default
    ~symbol_factory() = default;
    
    
    // OBTAIN SYMBOL
    
  public:
    
    //! manufacture a GiNaC symbol corresponding to a given name
    GiNaC::symbol& make_symbol(std::string name, boost::optional<std::string> latex_name = boost::none);
    
    
    // INTERNAL DATA
    
  private:
    
    // symbol database
    symbol_db symbols;
  
  };


#endif //LSSEFT_ANALYTIC_SYMBOL_FACTORY_H
