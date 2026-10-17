/* Unsigned remainder by a power of two. */
#include "test.h"

NOINLINE unsigned f(unsigned x) { return x % 16u; }
int test_call(void) { return (int)f(1000u); }

// RUN: test_call = 8
