/* Summing the hex digits of a number. */
#include "test.h"

NOINLINE int digits(unsigned x) { int s = 0; while (x) { s += (int)(x & 0xFu); x >>= 4; } return s; }
int test_call(void) { return digits(0xABCDu); }

// RUN: test_call = 46
