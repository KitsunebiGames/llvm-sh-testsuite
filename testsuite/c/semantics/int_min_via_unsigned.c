/* Negating INT_MIN through unsigned arithmetic. */
#include "test.h"

NOINLINE unsigned f(int x) { return 0u - (unsigned)x; }
int test_call(void) { return f(-2147483647 - 1) == 0x80000000u; }

// RUN: test_call = 1
