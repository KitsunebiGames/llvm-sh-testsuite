/* The conditional (?:) operator. */
#include "test.h"

NOINLINE int f(int a, int b) { return a > b ? a - b : b - a; }
int test_a(void) { return f(10, 3); }
int test_b(void) { return f(3, 10); }

// RUN: test_a = 7
// RUN: test_b = 7
