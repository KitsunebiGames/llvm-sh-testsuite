/* Insertion sort. */
#include "test.h"

NOINLINE void sort(int *a, int n) { for (int i = 1; i < n; i++) { int v = a[i], j = i - 1; while (j >= 0 && a[j] > v) { a[j + 1] = a[j]; j--; } a[j + 1] = v; } }
int test_call(void) { int a[5] = { 4, 1, 3, 9, 2 }; sort(a, 5); return a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4]; }

// RUN: test_call = 12349
