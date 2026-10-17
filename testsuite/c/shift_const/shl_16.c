/* Unsigned left shift by the constant 16. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a << 16; }

int test_a(void) { return f(1u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 65536
// RUN: test_b = 1450704896
// RUN: test_c = -65536
