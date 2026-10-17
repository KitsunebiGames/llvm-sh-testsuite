/* Computing prefix sums in place. */
#include "test.h"

NOINLINE void prefix(int *a, int n) { for (int i = 1; i < n; i++) a[i] += a[i - 1]; }
int test_call(void) { int a[5] = { 1, 2, 3, 4, 5 }; prefix(a, 5); return a[2] * 100 + a[4]; }

// RUN: test_call = 615
