/* Counting Collatz steps. */
#include "test.h"

NOINLINE int steps(unsigned n) { int s = 0; while (n != 1u) { n = (n & 1u) ? 3u * n + 1u : n >> 1; s++; } return s; }
int test_27(void) { return steps(27u); }

// RUN: test_27 = 111
