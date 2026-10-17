/* Counting trailing zeros with a loop. */
#include "test.h"

NOINLINE int ctz(unsigned x) { int n = 0; if (!x) return 32; while (!(x & 1u)) { x >>= 1; n++; } return n; }
int test_a(void) { return ctz(0x80u); }
int test_b(void) { return ctz(0x80000000u); }

// RUN: test_a = 7
// RUN: test_b = 31
