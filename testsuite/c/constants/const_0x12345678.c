/* Returning the constant 0x12345678 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 0x12345678; }

int test_value(void) { return f(); }

// RUN: test_value = 305419896
