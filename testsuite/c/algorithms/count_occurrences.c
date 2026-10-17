/* Counting occurrences of a value. */
#include "test.h"

NOINLINE int count(const int *a, int n, int v) { int c = 0; for (int i = 0; i < n; i++) c += a[i] == v; return c; }
int test_call(void) { int a[8] = { 1, 2, 1, 3, 1, 4, 1, 5 }; return count(a, 8, 1); }

// RUN: test_call = 4
