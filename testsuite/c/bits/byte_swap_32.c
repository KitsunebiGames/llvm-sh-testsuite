/* Swapping the bytes of a 32-bit word with shifts and masks. */
#include "test.h"

NOINLINE unsigned bswap(unsigned x) { return (x >> 24) | ((x >> 8) & 0xff00u) | ((x << 8) & 0xff0000u) | (x << 24); }
int test_call(void) { return bswap(0x12345678u) == 0x78563412u; }

// RUN: test_call = 1
