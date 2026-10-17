/* Returning the constant -129 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return -129; }

int test_value(void) { return f(); }

// RUN: test_value = -129
