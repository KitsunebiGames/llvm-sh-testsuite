/* Unsigned (logical) right shift by the constant 2. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a >> 2; }

int test_a(void) { return f(0x80000000u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 536870912
// RUN: test_b = 76354974
// RUN: test_c = 1073741823
