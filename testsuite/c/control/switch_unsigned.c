/* A switch on an unsigned value with a range check. */
#include "test.h"

NOINLINE int f(unsigned x) { switch (x) { case 0u: return 5; case 1u: return 6; case 2u: return 7; default: return 9; } }
int test_2(void) { return f(2u); }
int test_big(void) { return f(0xffffffffu); }

// RUN: test_2 = 7
// RUN: test_big = 9
