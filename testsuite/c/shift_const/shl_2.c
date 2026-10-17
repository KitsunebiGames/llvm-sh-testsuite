/* Unsigned left shift by the constant 2. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a << 2; }

int test_a(void) { return f(1u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 4
// RUN: test_b = 1221679584
// RUN: test_c = -4
