/* Rotating left by a variable amount. */
#include "test.h"

NOINLINE unsigned rotl(unsigned x, int n) { return (x << n) | (x >> (32 - n)); }
int test_call(void) { return rotl(0x80000001u, 4) == 0x00000018u; }

// RUN: test_call = 1
