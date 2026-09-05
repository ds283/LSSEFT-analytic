//
// Created by David Seery on 30/08/2017.
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

#include <sstream>

#include "special_functions.h"
#include "legendre_utils.h"

#include "shared/defaults.h"

#include "shared/exceptions.h"
#include "localizations/messages.h"

namespace special
  {

    REGISTER_FUNCTION(j, dummy());

  }   // namespace special


namespace Angular
  {

    REGISTER_FUNCTION(Cos, dummy());
    REGISTER_FUNCTION(LegP, dummy());

  }   // namespace Angular


namespace Fabrikant
  {

    GiNaC::ex FabJ_eval(const GiNaC::ex& lambda, const GiNaC::ex& mu, const GiNaC::ex& nu,
                        const GiNaC::ex& s, const GiNaC::ex& t, const GiNaC::ex& u)
      {
        const auto& lambda_num = GiNaC::ex_to<GiNaC::numeric>(lambda);
        const auto& mu_num = GiNaC::ex_to<GiNaC::numeric>(mu);
        const auto& nu_num = GiNaC::ex_to<GiNaC::numeric>(nu);

        if(lambda_num.to_int() != 0)
          throw exception(ERROR_FABJ_FIRST_ARG_NONZERO, exception_code::Fabrikant_error);

        if(mu_num.to_int() != nu_num.to_int())
          throw exception(ERROR_FABJ_SECOND_ARGS_NOT_EQUAL, exception_code::Fabrikant_error);

        if(mu_num.to_int() < 0)
          throw exception(ERROR_FABJ_SECOND_ARGS_NEGATIVE, exception_code::Fabrikant_error);

#ifdef REDUCE_FABRIKANT_INTEGRALS
        // The only three-Bessel integral this reduction can produce is the sigma = 0 family
        //   FabJ(0, n, n; s, t, u) = int_0^inf x^2 j_0(s x) j_n(t x) j_n(u x) dx ,
        // because the angular integral over the Rayleigh vector is always performed first, against a
        // kernel with no angular dependence on it, so only the l = 0 mode of its plane-wave expansion
        // survives (see one_loop_reduced_integral::one_loop_reduce_one_Rayleigh). This family has the
        // elementary closed form, valid for all n on the triangle |t-u| < s < t+u,
        //   FabJ(0, n, n; s, t, u) = pi / (4 s t u) * P_n( (t^2 + u^2 - s^2) / (2 t u) ) .
        // With the reduction's later substitution s -> sqrt(t^2 + u^2 - 2 t u x) the Legendre
        // argument is exactly x. The explicit table for n <= 4 that this replaced (2026-09-05) is
        // recovered term-for-term by expanding this expression; n = 5 was also checked numerically.
        // Outside the triangle the integral vanishes; that support condition is imposed by the caller.
        return GiNaC::Pi / (4*s*t*u) * LegP(static_cast<unsigned int>(mu_num.to_int()), (t*t + u*u - s*s) / (2*t*u));
#endif

        return FabJ(lambda, mu, nu, s, t, u).hold();
      }

    REGISTER_FUNCTION(FabJ, eval_func(FabJ_eval));

  }   // namespace Fabrikant
