/* Indexing a string literal. */
#include "test.h"

NOINLINE int f(int i) { return "SuperH"[i]; }
int test_0(void) { return f(0); }
int test_5(void) { return f(5); }

// RUN: test_0 = 83
// RUN: test_5 = 72
