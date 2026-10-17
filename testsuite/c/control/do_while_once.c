/* A do-while loop running its body once even when the condition is false. */
#include "test.h"

NOINLINE int f(int n) { int count = 0; do { count++; } while (count < n); return count; }
int test_zero(void) { return f(0); }
int test_five(void) { return f(5); }

// RUN: test_zero = 1
// RUN: test_five = 5
