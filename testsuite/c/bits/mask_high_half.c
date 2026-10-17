/* Selecting the high 16 bits. */
#include "test.h"

NOINLINE unsigned hi(unsigned x) { return x >> 16; }
NOINLINE unsigned lo(unsigned x) { return x & 0xFFFFu; }
int test_call(void) { return (int)(hi(0xABCD1234u) + lo(0xABCD1234u)); }

// RUN: test_call = 48641
