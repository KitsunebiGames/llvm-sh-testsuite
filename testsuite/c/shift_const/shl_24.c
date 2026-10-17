/* Unsigned left shift by the constant 24. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a << 24; }

int test_a(void) { return f(1u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 16777216
// RUN: test_b = 2013265920
// RUN: test_c = -16777216
