/* A GNU statement expression. */
#include "test.h"

NOINLINE int f(int x) { return ({ int t = x * 2; t + 1; }); }
int test_call(void) { return f(20); }

// RUN: test_call = 41
