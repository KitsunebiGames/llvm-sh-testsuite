/* Rotating an array left by one position. */
#include "test.h"

NOINLINE void rotl(int *a, int n) { int first = a[0]; for (int i = 0; i < n - 1; i++) a[i] = a[i + 1]; a[n - 1] = first; }
int test_call(void) { int a[4] = { 1, 2, 3, 4 }; rotl(a, 4); return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]; }

// RUN: test_call = 2341
