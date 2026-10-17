/* Unsigned (logical) right shift by the constant 16. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return a >> 16; }

int test_a(void) { return f(0x80000000u); }
int test_b(void) { return f(0x12345678u); }
int test_c(void) { return f(0xffffffffu); }

// RUN: test_a = 32768
// RUN: test_b = 4660
// RUN: test_c = 65535
