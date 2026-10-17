/* A loop with both a break and a return exit. */
#include "test.h"

NOINLINE int f(int a) { int i; for (i = 0; i < 20; i++) { if (i == a) return -i; if (i * 3 > 30) break; } return i; }
int test_return(void) { return f(4); }
int test_break(void) { return f(100); }

// RUN: test_return = -4
// RUN: test_break = 11
