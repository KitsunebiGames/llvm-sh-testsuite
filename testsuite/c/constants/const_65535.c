/* Returning the constant 65535 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 65535; }

int test_value(void) { return f(); }

// RUN: test_value = 65535
