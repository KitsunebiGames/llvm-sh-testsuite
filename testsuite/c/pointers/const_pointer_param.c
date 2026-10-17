/* Reading through a pointer to const. */
#include "test.h"

NOINLINE int sum(const int *p, int n) { int s = 0; for (int i = 0; i < n; i++) s += p[i]; return s; }
int test_call(void) { int a[3] = { 4, 5, 6 }; return sum(a, 3); }

// RUN: test_call = 15
