/* || not evaluating its right operand when the left is true. */
#include "test.h"

static int calls;
NOINLINE int side(int v) { calls++; return v; }
int test_skips(void) { calls = 0; int r = side(1) || side(0); return calls * 10 + r; }
int test_evaluates(void) { calls = 0; int r = side(0) || side(0); return calls * 10 + r; }

// RUN: test_skips = 11
// RUN: test_evaluates = 20
