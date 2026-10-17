/* A variable-length array (dynamic stack allocation). */
#include "test.h"

NOINLINE int f(int n) { int a[n]; for (int i = 0; i < n; i++) a[i] = i * i; int s = 0; for (int i = 0; i < n; i++) s += a[i]; return s; }
int test_10(void) { return f(10); }

// RUN: test_10 = 285
