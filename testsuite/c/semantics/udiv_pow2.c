/* Unsigned division by a power of two. */
#include "test.h"

NOINLINE unsigned f(unsigned x) { return x / 8u; }
int test_call(void) { return (int)f(1000u); }

// RUN: test_call = 125
