//
// Created by David Seery on 01/09/2017.
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

#ifndef LSSEFT_ANALYTIC_COMMON_H
#define LSSEFT_ANALYTIC_COMMON_H


#include "ginac/ginac.h"


//! type for a time function
using time_function = GiNaC::ex;

//! type for a substitution list
using subs_list = GiNaC::exmap;


constexpr auto PROGRAM_NAME = "LSSEFT-analytic";
constexpr auto PROGRAM_VERSION = "2017.1-beta1";
constexpr auto PROGRAM_COPYRIGHT = "(c) University of Sussex 2017";


#endif //LSSEFT_ANALYTIC_COMMON_H
