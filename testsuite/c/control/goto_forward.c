/* A forward goto skipping code. */
#include "test.h"

NOINLINE int f(int x) { int r = 1; if (x) goto skip; r = 2; skip: return r * 10; }
int test_skip(void) { return f(1); }
int test_noskip(void) { return f(0); }

// RUN: test_skip = 10
// RUN: test_noskip = 20
