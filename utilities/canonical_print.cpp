//
// Created for prompt 03 of the pre-Python-migration-fixes campaign.
// --@@
// Copyright (c) 2026 University of Sussex. All rights reserved.
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
// --@@
//

#include "canonical_print.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>


namespace canonical_print_impl
  {

    std::string default_print(const GiNaC::ex& e)
      {
        std::ostringstream oss;
        oss << e;
        return oss.str();
      }


    //! report an unexpected node class exactly once, so a full run produces at most one line
    //! per class rather than flooding stderr
    void report_unexpected_class(const std::string& class_name, const GiNaC::ex& e)
      {
        static std::set<std::string> already_reported;

        if(already_reported.insert(class_name).second)
          {
            std::cerr << "canonical_string(): unhandled GiNaC node class '" << class_name
                      << "' -- falling back to default print. First occurrence: " << e << '\n';
          }
      }


    std::string canonical_string_impl(const GiNaC::ex& e)
      {
        if(GiNaC::is_a<GiNaC::numeric>(e))
          {
            // rationals (and other numerics) already print canonically and are process-stable
            return default_print(e);
          }

        if(GiNaC::is_a<GiNaC::symbol>(e))
          {
            return GiNaC::ex_to<GiNaC::symbol>(e).get_name();
          }

        if(GiNaC::is_a<GiNaC::constant>(e))
          {
            // a GiNaC constant's default print is just its name (eg. "Pi"), which is stable
            return default_print(e);
          }

        if(GiNaC::is_a<GiNaC::power>(e))
          {
            std::string base = canonical_string_impl(e.op(0));
            std::string expo = canonical_string_impl(e.op(1));

            std::string result;
            result.reserve(base.size() + expo.size() + 6);
            result += "(";
            result += base;
            result += ")^(";
            result += expo;
            result += ")";
            return result;
          }

        if(GiNaC::is_a<GiNaC::add>(e))
          {
            std::vector<std::string> operands;
            operands.reserve(e.nops());
            for(size_t i = 0; i < e.nops(); ++i) operands.push_back(canonical_string_impl(e.op(i)));

            std::sort(operands.begin(), operands.end());

            std::string result{"["};
            for(size_t i = 0; i < operands.size(); ++i)
              {
                if(i > 0) result += "+";
                result += operands[i];
              }
            result += "]";
            return result;
          }

        if(GiNaC::is_a<GiNaC::mul>(e))
          {
            std::vector<std::string> operands;
            operands.reserve(e.nops());
            for(size_t i = 0; i < e.nops(); ++i) operands.push_back(canonical_string_impl(e.op(i)));

            std::sort(operands.begin(), operands.end());

            std::string result{"{"};
            for(size_t i = 0; i < operands.size(); ++i)
              {
                if(i > 0) result += "*";
                result += operands[i];
              }
            result += "}";
            return result;
          }

        if(GiNaC::is_a<GiNaC::function>(e))
          {
            // argument order is semantic (eg. Pk(a,b,k) vs Pk(b,a,k)) and must NOT be sorted
            std::string name = GiNaC::ex_to<GiNaC::function>(e).get_name();

            std::string result = name;
            result += "(";
            for(size_t i = 0; i < e.nops(); ++i)
              {
                if(i > 0) result += ",";
                result += canonical_string_impl(e.op(i));
              }
            result += ")";
            return result;
          }

        // anything else: fall through to GiNaC's default print. This branch is not expected to
        // fire for the expressions this tool actually hashes (measures, time functions, Wick
        // products, and expanded integrand*measure products), but is retained defensively -- see
        // the header comment. Report it so a full run makes the omission visible rather than
        // silently absorbing it.
        report_unexpected_class(GiNaC::ex_to<GiNaC::basic>(e).class_name(), e);
        return default_print(e);
      }

  }   // namespace canonical_print_impl


std::string canonical_string(const GiNaC::ex& e)
  {
    return canonical_print_impl::canonical_string_impl(e);
  }
