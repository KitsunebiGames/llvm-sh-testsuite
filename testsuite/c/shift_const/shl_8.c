/* Unsigned left shift by the constant 8. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a << 8; }

int test_a(void) { return f(1u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 256
// RUN: test_b = 878082048
// RUN: test_c = -256
