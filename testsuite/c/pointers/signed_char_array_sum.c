/* Summing negative signed bytes. */
#include "test.h"

signed char bytes[4] = { -100, 50, -1, 20 };
NOINLINE int f(const signed char *p, int n) { int s = 0; for (int i = 0; i < n; i++) s += p[i]; return s; }
int test_call(void) { return f(bytes, 4); }

// RUN: test_call = -31
