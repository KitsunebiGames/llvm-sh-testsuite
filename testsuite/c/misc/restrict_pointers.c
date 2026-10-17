/* Functions with restrict-qualified pointers. */
#include "test.h"

NOINLINE void add(int *restrict d, const int *restrict a, const int *restrict b, int n) { for (int i = 0; i < n; i++) d[i] = a[i] + b[i]; }
int test_call(void) { int a[3] = { 1, 2, 3 }, b[3] = { 10, 20, 30 }, d[3]; add(d, a, b, 3); return d[0] + d[1] + d[2]; }

// RUN: test_call = 66
