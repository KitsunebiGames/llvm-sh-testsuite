/* Right shift (arithmetic if signed, logical if unsigned) of a unsigned char by a variable count. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a, int n) { return a >> n; }

int test_shr_0(void) { return f(200, 3); }
int test_shr_1(void) { return f(255, 7); }

// RUN: test_shr_0 = 25
// RUN: test_shr_1 = 1
