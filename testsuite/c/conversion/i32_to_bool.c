/* Converting int to _Bool. */
#include "test.h"

NOINLINE int f(int x) { return (_Bool)x; }

int test_0(void) { return (int)f(0); }
int test_1(void) { return (int)f(5); }
int test_2(void) { return (int)f(-1); }

// RUN: test_0 = 0
// RUN: test_1 = 1
// RUN: test_2 = 1
