/* Unsigned (logical) right shift by the constant 4. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a >> 4; }

int test_a(void) { return f(0x80000000u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 134217728
// RUN: test_b = 19088743
// RUN: test_c = 268435455
