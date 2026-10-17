/* Multiplication by shifting and adding. */
#include "test.h"

NOINLINE unsigned mul(unsigned a, unsigned b) { unsigned r = 0; while (b) { if (b & 1u) r += a; a <<= 1; b >>= 1; } return r; }
int test_call(void) { return (int)mul(1234u, 567u); }

// RUN: test_call = 699678
