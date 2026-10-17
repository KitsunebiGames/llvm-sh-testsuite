/* Finding two elements adding up to a target. */
#include "test.h"

NOINLINE int two_sum(const int *a, int n, int t) { for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i] + a[j] == t) return i * 10 + j; return -1; }
int test_found(void) { int a[5] = { 2, 7, 11, 15, 4 }; return two_sum(a, 5, 19); }
int test_missing(void) { int a[3] = { 1, 2, 3 }; return two_sum(a, 3, 100); }

// RUN: test_found = 34
// RUN: test_missing = -1
