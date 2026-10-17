/* A function returning _Bool. */
#include "test.h"

NOINLINE _Bool f(int x) { return x > 10; }
int test_true(void) { return f(11) * 5; }
int test_false(void) { return f(10) * 5 + 1; }

// RUN: test_true = 5
// RUN: test_false = 1
