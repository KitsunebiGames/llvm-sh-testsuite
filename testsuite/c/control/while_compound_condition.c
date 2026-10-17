/* A while loop with a two-part condition. */
#include "test.h"

NOINLINE int f(int a, int b) { int c = 0; while (a > 0 && b > 0) { a--; b -= 2; c++; } return c; }
int test_a(void) { return f(10, 7); }
int test_b(void) { return f(2, 100); }

// RUN: test_a = 4
// RUN: test_b = 2
