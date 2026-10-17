/* The number of differing bits between two words. */
#include "test.h"

NOINLINE int dist(unsigned a, unsigned b) { unsigned x = a ^ b; int c = 0; while (x) { x &= x - 1u; c++; } return c; }
int test_call(void) { return dist(0xFF00u, 0x0FF0u); }

// RUN: test_call = 8
