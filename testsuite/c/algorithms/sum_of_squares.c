/* Summing squares. */
#include "test.h"

NOINLINE int f(int n) { int s = 0; for (int i = 1; i <= n; i++) s += i * i; return s; }
int test_20(void) { return f(20); }

// RUN: test_20 = 2870
