/* A _Static_assert that holds. */
#include "test.h"

_Static_assert(sizeof(int) == 4, "int must be 32 bits");
int test_call(void) { return 1; }

// RUN: test_call = 1
