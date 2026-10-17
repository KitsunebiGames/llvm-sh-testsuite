/* Returning the constant 2147483647 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 2147483647; }

int test_value(void) { return f(); }

// RUN: test_value = 2147483647
