/* Call another function through a constant-pool literal + jsr. */
#include "test.h"

NOINLINE int ext(int a, int b) { return a * b; }

NOINLINE int caller(int x) { return ext(x, 7) + 1; }

int test_caller(void) { return caller(4); }

// RUN: test_caller = 29
