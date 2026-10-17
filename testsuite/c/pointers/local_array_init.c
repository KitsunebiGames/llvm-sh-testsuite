/* An initialised local array. */
#include "test.h"

NOINLINE int f(int i) { int a[5] = { 2, 3, 5, 7, 11 }; return a[i]; }
int test_3(void) { return f(3); }
int test_4(void) { return f(4); }

// RUN: test_3 = 7
// RUN: test_4 = 11
