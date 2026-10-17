/* The maximum subarray sum (Kadane's algorithm). */
#include "test.h"

NOINLINE int kadane(const int *a, int n) { int best = a[0], cur = a[0]; for (int i = 1; i < n; i++) { cur = cur + a[i] > a[i] ? cur + a[i] : a[i]; if (cur > best) best = cur; } return best; }
static const int series[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
int test_call(void) { return kadane(series, 9); }

// RUN: test_call = 6
