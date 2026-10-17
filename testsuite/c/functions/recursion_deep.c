/* 200 levels of recursion. */
#include "test.h"

NOINLINE int sum(int n) { return n == 0 ? 0 : n + sum(n - 1); }
int test_200(void) { return sum(200); }

// RUN: test_200 = 20100
