/* A recursive function (factorial). */
#include "test.h"

NOINLINE int fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }
int test_10(void) { return fact(10); }
int test_1(void) { return fact(1); }

// RUN: test_10 = 3628800
// RUN: test_1 = 1
