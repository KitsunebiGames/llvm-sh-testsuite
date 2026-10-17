/* Converting short to unsigned int (sign extension). */
#include "test.h"

NOINLINE unsigned f(short x) { return x; }

int test_0(void) { return (int)f(-2); }
int test_1(void) { return (int)f(1000); }

// RUN: test_0 = -2
// RUN: test_1 = 1000
