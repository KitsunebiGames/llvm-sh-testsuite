/* Unsigned (logical) right shift by the constant 15. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a >> 15; }

int test_a(void) { return f(0x80000000u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 65536
// RUN: test_b = 9320
// RUN: test_c = 131071
