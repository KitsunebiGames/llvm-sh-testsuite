/* A post-increment inside a loop condition. */
#include "test.h"

NOINLINE int f(int n) { int i = 0, c = 0; while (i++ < n) c++; return c * 100 + i; }
int test_4(void) { return f(4); }

// RUN: test_4 = 405
