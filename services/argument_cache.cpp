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


#include <iostream>
#include <string_view>

#include "argument_cache.h"
#include "switches.h"

#include "shared/common.h"


namespace
  {

    //! print the fixed usage/help text listing every switch in switches.h.
    //! Does not attempt to reproduce Boost's program_options table formatting byte-for-byte;
    //! it lists the same switches with the same HELP_* strings (see log for prompt 01).
    void print_help()
      {
        std::cout << "Generic:\n"
                   << "  --" << SWITCH_HELP << "\t\t\t" << HELP_HELP << '\n'
                   << "  --" << SWITCH_VERSION << "\t\t\t" << HELP_VERSION << '\n'
                   << '\n'
                   << "Expression handling:\n"
                   << "  --" << SWITCH_AUTO_SYMMETRIZE << " / --" << SWITCH_NO_AUTO_SYMMETRIZE << "\t" << HELP_AUTO_SYMMETRIZE << '\n'
                   << "  --" << SWITCH_22_SYMMETRIZE << " / --" << SWITCH_NO_22_SYMMETRIZE << "\t" << HELP_22_SYMMETRIZE << '\n'
                   << '\n'
                   << "Backend control:\n"
                   << "  --" << SWITCH_COUNTERTERMS << " / --" << SWITCH_NO_COUNTERTERMS << "\t" << HELP_COUNTERTERMS << '\n'
                   << "  --" << SWITCH_OUTPUT_LONG << " <path>, -o <path>\t" << HELP_OUTPUT << '\n'
                   << "  --" << SWITCH_MATHEMATICA_OUTPUT << " <path>\t" << HELP_MATHEMATICA_OUTPUT << '\n';
      }

    [[noreturn]] void unrecognized_option(const std::string& arg)
      {
        std::cerr << PROGRAM_NAME << ": unrecognized option '" << arg << "'\n";
        exit(EXIT_FAILURE);
      }

    [[noreturn]] void missing_value(const std::string& arg)
      {
        std::cerr << PROGRAM_NAME << ": option '" << arg << "' requires a value\n";
        exit(EXIT_FAILURE);
      }

    std::filesystem::path make_absolute(const std::string& value)
      {
        std::filesystem::path outpath = value;
        if(!outpath.is_absolute()) outpath = std::filesystem::absolute(outpath);
        return outpath;
      }

  }   // unnamed namespace


argument_cache::argument_cache(int argc, char**& argv)
  {
    // hand-rolled argv scan, replacing Boost's program_options.
    //
    // Deliberate narrowings relative to program_options, both recorded in the log for prompt 01:
    //   - long options must be typed in full; program_options' unambiguous-prefix abbreviation
    //     guessing (e.g. "--counter" matching "--counterterms") is not reimplemented.
    //   - "-o<path>" (short option with attached value) is not supported; only "-o <path>" is.
    bool emitted_version = false;

    for(int i = 1; i < argc; ++i)
      {
        std::string arg{argv[i]};

        if(arg == "--help")
          {
            if(!emitted_version) std::cout << PROGRAM_NAME << " " << PROGRAM_VERSION << " " << PROGRAM_COPYRIGHT << '\n';
            print_help();
            exit(EXIT_SUCCESS);
          }

        if(arg == "--version")
          {
            std::cout << PROGRAM_NAME << " " << PROGRAM_VERSION << " " << PROGRAM_COPYRIGHT << '\n';
            emitted_version = true;
            continue;
          }

        if(arg == "--auto-symmetrize")    { this->auto_symmetrize = true;  continue; }
        if(arg == "--no-auto-symmetrize") { this->auto_symmetrize = false; continue; }
        if(arg == "--symmetrize-22")      { this->symmetrize_22 = true;    continue; }
        if(arg == "--no-symmetrize-22")   { this->symmetrize_22 = false;   continue; }
        if(arg == "--counterterms")       { this->counterterms = true;     continue; }
        if(arg == "--no-counterterms")    { this->counterterms = false;    continue; }

        // "--output=<path>" form
        if(arg.rfind("--output=", 0) == 0)
          {
            this->output_root = make_absolute(arg.substr(std::string_view{"--output="}.size()));
            continue;
          }

        // "--mathematica-output=<path>" form
        if(arg.rfind("--mathematica-output=", 0) == 0)
          {
            this->output_mma = make_absolute(arg.substr(std::string_view{"--mathematica-output="}.size()));
            continue;
          }

        // "--output <path>" / "-o <path>" form
        if(arg == "--output" || arg == "-o")
          {
            if(i + 1 >= argc) missing_value(arg);
            this->output_root = make_absolute(argv[++i]);
            continue;
          }

        // "--mathematica-output <path>" form
        if(arg == "--mathematica-output")
          {
            if(i + 1 >= argc) missing_value(arg);
            this->output_mma = make_absolute(argv[++i]);
            continue;
          }

        unrecognized_option(arg);
      }
  }


bool argument_cache::get_auto_symmetrize() const
  {
    return this->auto_symmetrize;
  }


bool argument_cache::get_symmetrize_22() const
  {
    return this->symmetrize_22;
  }


const std::filesystem::path& argument_cache::get_output_path() const
  {
    return this->output_root;
  }


bool argument_cache::get_counterterms() const
  {
    return this->counterterms;
  }


const std::filesystem::path& argument_cache::get_Mathematica_output() const
  {
    return this->output_mma;
  }


