/* Returning the constant -128 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return -128; }

int test_value(void) { return f(); }

// RUN: test_value = -128
