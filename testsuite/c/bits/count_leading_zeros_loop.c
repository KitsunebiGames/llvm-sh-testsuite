/* Counting leading zeros with a loop. */
#include "test.h"

NOINLINE int clz(unsigned x) { int n = 0; if (!x) return 32; while (!(x & 0x80000000u)) { x <<= 1; n++; } return n; }
int test_a(void) { return clz(1u); }
int test_b(void) { return clz(0x00f00000u); }

// RUN: test_a = 31
// RUN: test_b = 8
