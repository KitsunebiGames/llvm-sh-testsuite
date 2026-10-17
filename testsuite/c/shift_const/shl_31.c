/* Unsigned left shift by the constant 31. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a << 31; }

int test_a(void) { return f(1u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = -2147483648
// RUN: test_b = 0
// RUN: test_c = -2147483648
