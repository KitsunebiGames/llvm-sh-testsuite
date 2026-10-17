/* Unsigned remainder by the constant 10. */
#include "test.h"

NOINLINE unsigned f(unsigned x) { return x % 10u; }
int test_call(void) { return (int)f(12345u); }

// RUN: test_call = 5
