/* Reversing the 32 bits of a word. */
#include "test.h"

NOINLINE unsigned rev(unsigned x) { unsigned r = 0; for (int i = 0; i < 32; i++) { r = (r << 1) | (x & 1u); x >>= 1; } return r; }
int test_call(void) { return (int)rev(0x00000001u) + (int)(rev(0x80000000u) * 2u); }

// RUN: test_call = -2147483646
