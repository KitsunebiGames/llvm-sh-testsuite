/* Nested conditional operators (clamp). */
#include "test.h"

NOINLINE int clamp(int x, int lo, int hi) { return x < lo ? lo : x > hi ? hi : x; }
int test_low(void) { return clamp(-5, 0, 10); }
int test_mid(void) { return clamp(7, 0, 10); }
int test_high(void) { return clamp(50, 0, 10); }

// RUN: test_low = 0
// RUN: test_mid = 7
// RUN: test_high = 10
