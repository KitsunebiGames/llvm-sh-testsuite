/* Passing a large struct by value (callee changes its own copy). */
#include "test.h"

struct big { int v[6]; };
NOINLINE int mangle(struct big b) { b.v[0] = 99; return b.v[0] + b.v[5]; }
int test_call(void) { struct big b = { { 1, 2, 3, 4, 5, 6 } }; int r = mangle(b); return r * 100 + b.v[0]; }

// RUN: test_call = 10501
