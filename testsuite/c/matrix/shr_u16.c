/* Right shift (arithmetic if signed, logical if unsigned) of a unsigned short by a variable count. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a, int n) { return a >> n; }

int test_shr_0(void) { return f(65535, 4); }
int test_shr_1(void) { return f(40000, 15); }

// RUN: test_shr_0 = 4095
// RUN: test_shr_1 = 1
