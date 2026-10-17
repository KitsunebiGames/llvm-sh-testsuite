/* Returning the constant 127 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 127; }

int test_value(void) { return f(); }

// RUN: test_value = 127
