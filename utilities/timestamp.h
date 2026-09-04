//
// Created by David Seery on 01/10/2017.
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

#ifndef LSSEFT_ANALYTIC_TIMESTAMP_H
#define LSSEFT_ANALYTIC_TIMESTAMP_H


#include <array>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <string>


//! minimal UTC timestamp, replacing Boost's posix_time::ptime and
//! posix_time::second_clock::universal_time(). to_string() reproduces the exact shape of
//! Boost's to_simple_string() at second resolution, e.g. "2018-Jul-19 23:52:20". That string is
//! written into every generated file's header and is the entire return value of
//! LSSEFT::pipeline_id(), so its shape must not change.
class utc_timestamp
  {

  public:

    //! constructor captures the current UTC time, to second resolution
    utc_timestamp()
      : captured(std::chrono::system_clock::now())
      {
      }

    //! format as "YYYY-Mmm-DD HH:MM:SS", matching Boost's to_simple_string()
    std::string to_string() const
      {
        std::time_t tt = std::chrono::system_clock::to_time_t(this->captured);

        // std::gmtime returns a pointer to internal static storage; copy it out immediately.
        // The month table is hard-coded (not strftime("%b")) so the three-letter English
        // abbreviation does not depend on the process locale.
        std::tm utc = *std::gmtime(&tt);

        static constexpr std::array<const char*, 12> month_names
          {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
          };

        char buf[32];
        std::snprintf(buf, sizeof(buf), "%04d-%s-%02d %02d:%02d:%02d",
                      utc.tm_year + 1900, month_names[static_cast<std::size_t>(utc.tm_mon)], utc.tm_mday,
                      utc.tm_hour, utc.tm_min, utc.tm_sec);

        return std::string{buf};
      }

  private:

    //! captured time point
    std::chrono::system_clock::time_point captured;

  };


#endif //LSSEFT_ANALYTIC_TIMESTAMP_H
