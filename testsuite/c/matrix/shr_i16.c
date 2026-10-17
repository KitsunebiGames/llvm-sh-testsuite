/* Right shift (arithmetic if signed, logical if unsigned) of a short by a variable count. */
#include "test.h"

NOINLINE short f(short a, int n) { return a >> n; }

int test_shr_0(void) { return f(-32768, 4); }
int test_shr_1(void) { return f(30000, 5); }

// RUN: test_shr_0 = -2048
// RUN: test_shr_1 = 937
