/* Unlisted struct members being zero-initialised. */
#include "test.h"

struct many { int v[6]; };
NOINLINE int f(int i) { struct many m = { { 9 } }; return m.v[i]; }
int test_0(void) { return f(0); }
int test_5(void) { return f(5); }

// RUN: test_0 = 9
// RUN: test_5 = 0
