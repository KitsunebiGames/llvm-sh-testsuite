/* Unsigned (logical) right shift by the constant 8. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a >> 8; }

int test_a(void) { return f(0x80000000u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 8388608
// RUN: test_b = 1193046
// RUN: test_c = 16777215
