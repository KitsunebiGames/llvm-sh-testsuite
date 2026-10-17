/* Swapping the bytes of a 16-bit value. */
#include "test.h"

NOINLINE unsigned short bswap16(unsigned short x) { return (unsigned short)((x >> 8) | (x << 8)); }
int test_call(void) { return bswap16(0x1234); }

// RUN: test_call = 13330
