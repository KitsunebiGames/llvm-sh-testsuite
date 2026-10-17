/* Summing the first n triangle numbers. */
#include "test.h"

NOINLINE int f(int n) { int s = 0, t = 0; for (int i = 1; i <= n; i++) { t += i; s += t; } return s; }
int test_10(void) { return f(10); }

// RUN: test_10 = 220
