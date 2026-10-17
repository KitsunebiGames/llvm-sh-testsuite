/* Isolating the lowest set bit with x & -x. */
#include "test.h"

NOINLINE unsigned low(unsigned x) { return x & (0u - x); }
int test_call(void) { return (int)low(0x5800u); }

// RUN: test_call = 2048
