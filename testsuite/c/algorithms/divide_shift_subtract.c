/* Unsigned division by shifting and subtracting. */
#include "test.h"

NOINLINE unsigned udiv(unsigned n, unsigned d) { unsigned q = 0, r = 0; for (int i = 31; i >= 0; i--) { r = (r << 1) | ((n >> i) & 1u); if (r >= d) { r -= d; q |= 1u << i; } } return q; }
int test_call(void) { return (int)udiv(1000000u, 37u); }

// RUN: test_call = 27027
