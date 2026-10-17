/* An anonymous struct inside a union. */
#include "test.h"

union v { struct { short lo, hi; }; int all; };
NOINLINE int f(void) { union v x; x.lo = 5; x.hi = 7; return x.lo * 10 + x.hi; }
int test_call(void) { return f(); }

// RUN: test_call = 57
