/* Converting unsigned int to int. */
#include "test.h"

NOINLINE int f(unsigned x) { return (int)x; }

int test_0(void) { return (int)f(0xffffffffu); }
int test_1(void) { return (int)f(0x80000000u); }
int test_2(void) { return (int)f(5u); }

// RUN: test_0 = -1
// RUN: test_1 = -2147483648
// RUN: test_2 = 5
