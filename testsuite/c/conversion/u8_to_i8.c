/* Reinterpreting unsigned char as signed char. */
#include "test.h"

NOINLINE int f(unsigned char x) { return (signed char)x; }

int test_0(void) { return (int)f(200); }
int test_1(void) { return (int)f(100); }

// RUN: test_0 = -56
// RUN: test_1 = 100
