/* An inner variable shadowing an outer one. */
#include "test.h"

NOINLINE int f(int x) { int r = x; { int x = 100; r += x; } return r + x; }
int test_call(void) { return f(5); }

// RUN: test_call = 110
