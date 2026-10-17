/* Counting set bits by clearing the lowest bit. */
#include "test.h"

NOINLINE int pop(unsigned x) { int c = 0; while (x) { x &= x - 1u; c++; } return c; }
int test_call(void) { return pop(0x12345678u); }

// RUN: test_call = 13
