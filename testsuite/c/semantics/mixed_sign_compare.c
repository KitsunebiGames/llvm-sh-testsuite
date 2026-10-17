/* Comparing int with unsigned converting the int to unsigned. */
#include "test.h"

NOINLINE int f(int a, unsigned b) { return a < b; }
int test_call(void) { return f(-1, 1u); }

// RUN: test_call = 0
