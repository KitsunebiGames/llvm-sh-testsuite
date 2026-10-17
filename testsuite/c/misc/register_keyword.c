/* Variables declared with the register keyword. */
#include "test.h"

NOINLINE int f(int n) { register int s = 0; for (register int i = 0; i < n; i++) s += i; return s; }
int test_call(void) { return f(10); }

// RUN: test_call = 45
