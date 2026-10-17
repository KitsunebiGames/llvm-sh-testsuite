/* Writing to and reading from a local array. */
#include "test.h"

NOINLINE int f(int n) { int a[8]; for (int i = 0; i < 8; i++) a[i] = i * n; a[3] += 100; return a[3] + a[7]; }
int test_call(void) { return f(5); }

// RUN: test_call = 150
