//
// Created by David Seery on 17/10/2017.
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

#ifndef LSSEFT_ANALYTIC_TIMING_INSTRUMENT_H
#define LSSEFT_ANALYTIC_TIMING_INSTRUMENT_H


#include <chrono>
#include <string>


class timing_instrument
  {

    // CONSTRUCTOR, DESTRUCTOR

  public:

    //! timing instrument establishes a timer and records its name
    timing_instrument(std::string name_);

    //! destructor reports details
    ~timing_instrument();


    // INTERNAL DATA

  private:

    //! wall-clock start time, replacing Boost's timer::cpu_timer (only .wall was ever used)
    std::chrono::steady_clock::time_point start_time{std::chrono::steady_clock::now()};

    //! wall-clock stop time
    std::chrono::steady_clock::time_point stop_time;

    //! cache name
    const std::string name;

  };


#endif //LSSEFT_ANALYTIC_TIMING_INSTRUMENT_H
