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

#ifndef LSSEFT_ANALYTIC_CANONICAL_PRINT_H
#define LSSEFT_ANALYTIC_CANONICAL_PRINT_H


#include <string>

#include "ginac/ginac.h"


//! Produce a print-order-independent canonical string for a GiNaC expression.
//!
//! GiNaC 1.8.10 seeds its expression hash from a per-process value, so the canonical ordering
//! GiNaC itself imposes on the operands of a `mul` or `add` node -- and therefore the
//! default-printed form of an expression -- differs between processes even when the expression
//! is mathematically identical (see RECONCILIATION.md Sec. 3.2 and validation/NONDETERMINISM.md).
//! `canonical_string()` removes that source of non-determinism by walking the expression
//! structurally and sorting `add`/`mul` operands lexicographically on their own canonical
//! strings, rather than trusting GiNaC's (process-random) operand order.
//!
//! This is a *sort key and hash input*, not a pretty-printer: the result does not have to be
//! re-parseable, only stable across processes and injective enough to order and hash by. Do not
//! use it as a substitute for `GiNaC::csrc` or default printing in emitted code.
//!
//! Node handling (applied recursively):
//!   - numeric:  default GiNaC print (rationals print canonically and are already stable)
//!   - symbol:   `get_name()`
//!   - constant: default GiNaC print (a constant's default print is just its name)
//!   - function: `name(` + canonical of each argument, *in argument order* + `)` -- argument
//!               order is semantic (e.g. Pk(a,b,k)) and must not be sorted
//!   - power:    `(` + canonical(base) + `)^(` + canonical(exponent) + `)`
//!   - add:      canonical of each operand, sorted lexicographically, joined with `+`, in `[...]`
//!   - mul:      canonical of each operand, sorted lexicographically, joined with `*`, in `{...}`
//!   - anything else: falls back to GiNaC's default print, and logs the class name to stderr
//!               (once per class) so an unexpected node kind is noticed rather than silently
//!               absorbed. If this ever fires in a real run, the table above needs extending.
std::string canonical_string(const GiNaC::ex& e);


#endif //LSSEFT_ANALYTIC_CANONICAL_PRINT_H
