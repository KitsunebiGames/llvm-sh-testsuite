/* Converting unsigned char to int (zero extension). */
#include "test.h"

NOINLINE int f(unsigned char x) { return x; }

int test_0(void) { return (int)f(200); }
int test_1(void) { return (int)f(1); }

// RUN: test_0 = 200
// RUN: test_1 = 1
