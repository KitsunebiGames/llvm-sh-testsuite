/* Returning the constant 0 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 0; }

int test_value(void) { return f(); }

// RUN: test_value = 0
