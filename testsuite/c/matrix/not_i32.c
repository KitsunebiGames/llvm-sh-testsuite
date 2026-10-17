/* Bitwise NOT of a int argument. */
#include "test.h"

NOINLINE int f(int a) { return ~a; }

int test_not_0(void) { return f(0); }
int test_not_1(void) { return f(-1); }
int test_not_2(void) { return f(0x12345678); }

// RUN: test_not_0 = -1
// RUN: test_not_1 = 0
// RUN: test_not_2 = -305419897
