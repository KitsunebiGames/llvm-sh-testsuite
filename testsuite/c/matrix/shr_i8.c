/* Right shift (arithmetic if signed, logical if unsigned) of a signed char by a variable count. */
#include "test.h"

NOINLINE signed char f(signed char a, int n) { return a >> n; }

int test_shr_0(void) { return f(-64, 2); }
int test_shr_1(void) { return f(100, 3); }
int test_shr_2(void) { return f(-1, 7); }

// RUN: test_shr_0 = -16
// RUN: test_shr_1 = 12
// RUN: test_shr_2 = -1
