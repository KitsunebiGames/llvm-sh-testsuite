/* A static inline function that is expected to be inlined. */
#include "test.h"

static inline int sq(int x) { return x * x; }
NOINLINE int f(int a) { return sq(a) + sq(a + 1); }
int test_call(void) { return f(4); }

// RUN: test_call = 41
