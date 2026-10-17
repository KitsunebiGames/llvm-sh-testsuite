/* Function calls inside a loop condition. */
#include "test.h"

static int left = 5;
NOINLINE int more(void) { return left-- > 0; }
NOINLINE int f(void) { int c = 0; while (more()) c++; return c; }
int test_call(void) { left = 5; return f(); }

// RUN: test_call = 5
