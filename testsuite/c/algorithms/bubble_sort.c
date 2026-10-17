/* Bubble sort. */
#include "test.h"

NOINLINE void sort(int *a, int n) { for (int i = 0; i < n - 1; i++) for (int j = 0; j < n - 1 - i; j++) if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; } }
int test_call(void) { int a[6] = { 5, -2, 9, 0, 3, 1 }; sort(a, 6); return a[0] * 100000 + a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5]; }

// RUN: test_call = -198641
