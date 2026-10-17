/* A loop whose body never runs. */
#include "test.h"

NOINLINE int f(int n) { int s = 7; for (int i = 0; i < n; i++) s = 0; return s; }
int test_none(void) { return f(0); }
int test_neg(void) { return f(-3); }

// RUN: test_none = 7
// RUN: test_neg = 7
