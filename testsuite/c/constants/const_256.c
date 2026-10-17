/* Returning the constant 256 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 256; }

int test_value(void) { return f(); }

// RUN: test_value = 256
