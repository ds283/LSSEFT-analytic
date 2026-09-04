// validation/ginac_ordering_probe.cpp
//
// Minimal reproduction of the library behaviour that makes LSSEFT-analytic's emitted tree
// non-reproducible between processes. This is a GiNaC property, not a defect in this project;
// the probe is kept here so a future reader does not blame the project for it, and so the
// check can be repeated cheaply after a GiNaC upgrade.
//
// GiNaC 1.8.10 seeds its expression hash from a runtime address. The hash of a given expression
// therefore changes from process to process, and with it the canonical ordering of `mul` and
// `add` operands, and with it the printed form. Run this five times: during planning it printed
// three distinct orderings in five runs, with a different `Pi^(-2)` hash every time.
//
// Build and run:
//
//   c++ -std=c++17 -O2 $(pkg-config --cflags ginac) validation/ginac_ordering_probe.cpp \
//       -o /tmp/ginac_ordering_probe $(pkg-config --libs ginac)
//   for i in 1 2 3 4 5; do /tmp/ginac_ordering_probe; done
//
// Expected: the printed expression is *mathematically* the same every time, but the operand
// order (and the hash) varies. If a future GiNaC prints the same line five times with the same
// hash, this behaviour has been fixed upstream and prompt 03's workaround can be revisited.
//
// See: prompts/pre-python-migration-fixes/RECONCILIATION.md Sec. 3.2,
//      validation/NONDETERMINISM.md.

#include <iostream>

#include "ginac/ginac.h"

int main()
  {
    GiNaC::symbol a("a"), b("b"), z("z");

    GiNaC::ex e = GiNaC::pow(GiNaC::Pi, -2) * a * b * GiNaC::sin(z)
                  * GiNaC::pow(a, 3) * GiNaC::numeric(3, 7);

    // The hash is printed alongside the expression because it is the actual carrier of the
    // non-determinism: it is what GiNaC's operand comparator consults, and (via the
    // printed-string hashes in one_loop_element_key and LSSEFT_kernel) what ends up keying this
    // project's two std::unordered_maps.
    std::cout << e << "      hash of Pi^(-2) = " << GiNaC::pow(GiNaC::Pi, -2).gethash() << '\n';

    return 0;
  }
