/* Unsigned addition wrapping past the maximum. */
#include "test.h"

NOINLINE unsigned f(unsigned a, unsigned b) { return a + b; }
int test_call(void) { return (int)f(0xffffffffu, 2u); }

// RUN: test_call = 1
