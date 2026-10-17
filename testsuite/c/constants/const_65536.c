/* Returning the constant 65536 (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return 65536; }

int test_value(void) { return f(); }

// RUN: test_value = 65536
