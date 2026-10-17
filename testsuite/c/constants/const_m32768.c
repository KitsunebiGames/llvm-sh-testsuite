/* Returning the constant -32768 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return -32768; }

int test_value(void) { return f(); }

// RUN: test_value = -32768
