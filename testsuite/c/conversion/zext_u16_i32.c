/* Converting unsigned short to int (zero extension). */
#include "test.h"

NOINLINE int f(unsigned short x) { return x; }

int test_0(void) { return (int)f(60000); }
int test_1(void) { return (int)f(7); }

// RUN: test_0 = 60000
// RUN: test_1 = 7
