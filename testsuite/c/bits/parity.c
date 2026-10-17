/* Computing the parity of a word. */
#include "test.h"

NOINLINE int parity(unsigned x) { x ^= x >> 16; x ^= x >> 8; x ^= x >> 4; x ^= x >> 2; x ^= x >> 1; return (int)(x & 1u); }
int test_odd(void) { return parity(0x7u); }
int test_even(void) { return parity(0x3u); }

// RUN: test_odd = 1
// RUN: test_even = 0
