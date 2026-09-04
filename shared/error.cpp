//
// Created by David Seery on 23/08/2017.
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

#include <iostream>

#include "error.h"
#include "ansi_colour_codes.h"

#include "localizations/messages.h"

#include "utilities/timestamp.h"


void error_handler::error(std::string msg)
  {
    std::string nowstr = utc_timestamp{}.to_string();

    std::cout << ANSI_BOLD_RED;
    std::cout << "lsseft-analytic [" << nowstr << "]: " << msg << '\n';
    std::cout << ANSI_NORMAL;
  }


void error_handler::warn(std::string msg)
  {
    std::string nowstr = utc_timestamp{}.to_string();

    std::cout << ANSI_BOLD_MAGENTA;
    std::cout << WARNING_LABEL << " ";
    std::cout << ANSI_NORMAL;
    std::cout << "lsseft-analytic [" << nowstr << "]: " << msg << '\n';
  }


void error_handler::info(std::string msg)
  {
    std::string nowstr = utc_timestamp{}.to_string();

    std::cout << "lsseft-analytic [" << nowstr << "]: " << msg << '\n';
  }


void error_handler::announce(std::string msg)
  {
    std::string nowstr = utc_timestamp{}.to_string();

    std::cout << ANSI_BOLD_GREEN;
    std::cout << "lsseft-analytic [" << nowstr << "]: " << msg << '\n';
    std::cout << ANSI_NORMAL;
  }
