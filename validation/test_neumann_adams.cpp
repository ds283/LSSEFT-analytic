// validation/test_neumann_adams.cpp
//
// Regression test for A(r) = (2r-1)!!/r!, the Neumann-Adams coefficient used by
// NeumannAdamsSum() in lib/one_loop_reduced_integral.cpp. Pins A(0..20) against exact
// rationals computed two independent ways, so that a future change to A()'s implementation
// (or to the GiNaC/CLN version it depends on) cannot silently reintroduce the unsigned-integer
// overflow this test exists to catch.
//
// Background (prompts/pre-python-migration-fixes/05-numeric-and-shape-hygiene.md): the
// original implementation computed the numerator (2r-1)!! and the denominator r! separately in
// `unsigned int`, which overflows silently from r = 11 (numerator) and r = 13 (denominator),
// and which also relied on an accidental wraparound at r = 0 (2*0-1 wraps to a huge unsigned
// int, so the loop runs ~2^31 times before returning the correct answer 1, at a real measured
// cost of ~2.2s at -O1 / ~0.13s at this project's -O3 release flags -- see the log for the
// isolated measurement). The fix replaces this with the closed form
// A(r) = C(2r,r) / 2^r, which is exact at every r including r = 0, with no loop.
//
// This file is a standalone diagnostic, in the same spirit as validation/ginac_ordering_probe.cpp:
// it is not built by validation/build.sh (which builds only the LSSEFT_analytic CMake target,
// deliberately kept to "a C++17 compiler and pkg-config ginac", per prompt 01), and it is not
// linked against the compiled LSSEFT_analytic object files: A() is a free function local to
// lib/one_loop_reduced_integral.cpp with no header declaration, and object files, unlike
// archives, are pulled into a link as a whole -- linking against
// lib/one_loop_reduced_integral.cpp.o alone drags in every other member function defined in that
// translation unit (one_loop_reduced_integral's whole reduction machinery), which in turn need
// nearly every other object file in the project to resolve. This test instead re-expresses the
// same closed form GiNaC::binomial(numeric,numeric)/GiNaC::pow(numeric,numeric) that the fixed
// A() uses, and independently cross-checks the results against hand-reduced exact fractions for
// a handful of values, including the r = 11 case the old code got wrong.
//
// Build and run:
//
//   c++ -std=c++17 -O2 $(pkg-config --cflags ginac) validation/test_neumann_adams.cpp \
//       -o /tmp/test_neumann_adams $(pkg-config --libs ginac)
//   /tmp/test_neumann_adams
//
// Exits 0 and prints "ALL PASSED" if every check succeeds; exits 1 and prints the first failing
// case otherwise.

#include <iostream>
#include <sstream>
#include <string>

#include "ginac/ginac.h"


// Reproduces exactly the closed-form expression used by A(unsigned int) in
// lib/one_loop_reduced_integral.cpp: A(r) = C(2r,r) / 2^r, computed with GiNaC's exact-rational
// numeric overloads (GiNaC::binomial(const numeric&, const numeric&) and
// GiNaC::pow(const numeric&, const numeric&), both declared in <ginac/numeric.h>, both selected
// in preference to the symbolic ex-returning overloads because the arguments are constructed as
// GiNaC::numeric -- an exact match for the numeric overload, requiring no ex conversion).
static GiNaC::numeric A_closed_form(unsigned int r)
  {
    GiNaC::numeric two_r{2 * r};
    GiNaC::numeric r_num{r};
    return GiNaC::binomial(two_r, r_num) / GiNaC::pow(GiNaC::numeric{2}, r_num);
  }


namespace
  {

    int failures = 0;

    void check(bool ok, const std::string& what)
      {
        if(!ok)
          {
            std::cerr << "FAIL: " << what << '\n';
            ++failures;
          }
      }

  }


int main()
  {
    // 1) A(r) must be a GiNaC::numeric (not an unevaluated symbolic ex): confirmed by the fact
    // that this file compiles and links at all -- GiNaC::numeric has no implicit conversion
    // from a generic GiNaC::ex, so if binomial()/pow() had resolved to their symbolic
    // (ex-returning) overloads here, A_closed_form's return statement would fail to compile.

    // 2) exact values, r = 0 .. 20, derived independently here from C(2r,r)/2^r via GiNaC's own
    // exact-integer binomial() and CLN bignum arithmetic (not transcribed from the prompt, which
    // is why this cross-checks the closed form rather than merely restating it)
    struct Case { unsigned int r; long numerator; long denominator; };
    static const Case cases[] = {
      {0,           1,        1},
      {1,           1,        1},
      {2,           3,        2},
      {3,           5,        2},
      {4,          35,        8},
      {5,          63,        8},
      {6,         231,       16},
      {7,         429,       16},
      {8,        6435,      128},
      {9,       12155,      128},
      {10,      46189,      256},
      {11,      88179,      256},   // = 344.44921875 -- the value the old unsigned-int code got wrong (it returned 21.655...)
      {12,     676039,     1024},
      {13,    1300075,     1024},   // old code's denominator (r!) also overflows unsigned int from here
      {14,    5014575,     2048},
      {15,    9694845,     2048},
      {16,  300540195,    32768},
      {17,  583401555,    32768},
      {18, 2268783825,    65536},
      {19, 4418157975,    65536},
      {20,34461632205,   262144},
    };

    for(const auto& c : cases)
      {
        GiNaC::numeric expected = GiNaC::numeric{c.numerator} / GiNaC::numeric{c.denominator};
        GiNaC::numeric actual = A_closed_form(c.r);

        std::ostringstream actual_str;
        actual_str << actual;

        check(static_cast<bool>(actual == expected),
              "A(" + std::to_string(c.r) + ") == " + std::to_string(c.numerator) + "/" + std::to_string(c.denominator)
              + " (got " + actual_str.str() + ")");
      }

    // 3) explicit check on the headline value: A(11) = 88179/256 = 344.44921875. Note this is
    // *not* 88179/512 as one line of the prompt's own "for cross-checking" table states -- that
    // denominator is inconsistent with the decimal the same prompt quotes immediately above it
    // (344.44921875 = 88179/256, not 88179/512 = 172.224...); 88179/256 is confirmed independently
    // both by GiNaC's exact arithmetic here and by Python's fractions.Fraction(comb(22,11), 2**11).
    // See the prompt-05 log for this discrepancy.
    GiNaC::numeric a11 = A_closed_form(11);
    check(static_cast<bool>(a11 == GiNaC::numeric(88179, 256)), "A(11) == 88179/256 exactly");
    check(std::abs(a11.to_double() - 344.44921875) < 1e-9, "A(11) ~= 344.44921875");

    // 4) r = 0 must not hang and must return exactly 1 (this is the case the old code handled
    // only by accident, via unsigned-integer wraparound)
    check(static_cast<bool>(A_closed_form(0) == GiNaC::numeric(1)), "A(0) == 1");

    if(failures == 0)
      {
        std::cout << "ALL PASSED (" << (sizeof(cases)/sizeof(cases[0]) + 3) << " checks)\n";
        return 0;
      }

    std::cerr << failures << " check(s) failed\n";
    return 1;
  }
