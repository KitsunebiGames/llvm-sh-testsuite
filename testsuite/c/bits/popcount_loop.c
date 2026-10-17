/* Counting set bits with a loop. */
#include "test.h"

NOINLINE int pop(unsigned x) { int c = 0; while (x) { c += x & 1u; x >>= 1; } return c; }
int test_call(void) { return pop(0xF0F0F00Fu); }

// RUN: test_call = 16
