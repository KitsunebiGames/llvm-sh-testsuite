/* Returning the constant 255 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 255; }

int test_value(void) { return f(); }

// RUN: test_value = 255
