/* An array with designated initialisers. */
#include "test.h"

NOINLINE int f(int i) { int a[6] = { [4] = 40, [1] = 10 }; return a[i]; }
int test_1(void) { return f(1); }
int test_3(void) { return f(3); }
int test_4(void) { return f(4); }

// RUN: test_1 = 10
// RUN: test_3 = 0
// RUN: test_4 = 40
