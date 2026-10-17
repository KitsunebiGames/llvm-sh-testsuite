/* Converting signed char to unsigned int (sign extension). */
#include "test.h"

NOINLINE unsigned f(signed char x) { return x; }

int test_0(void) { return (int)f(-1); }
int test_1(void) { return (int)f(100); }

// RUN: test_0 = -1
// RUN: test_1 = 100
