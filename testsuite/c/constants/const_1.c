/* Returning the constant 1 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 1; }

int test_value(void) { return f(); }

// RUN: test_value = 1
