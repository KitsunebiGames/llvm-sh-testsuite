/* Forwarding arguments in a different order. */
#include "test.h"

NOINLINE int g(int a, int b) { return a - b; }
NOINLINE int f(int a, int b) { return g(b, a); }
int test_call(void) { return f(3, 10); }

// RUN: test_call = 7
