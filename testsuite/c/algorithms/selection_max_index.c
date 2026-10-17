/* Finding the index of the maximum element. */
#include "test.h"

NOINLINE int argmax(const int *a, int n) { int best = 0; for (int i = 1; i < n; i++) if (a[i] > a[best]) best = i; return best; }
int test_call(void) { int a[7] = { 3, -1, 44, 7, 44, 2, 0 }; return argmax(a, 7); }

// RUN: test_call = 2
