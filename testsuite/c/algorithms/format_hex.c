/* Formatting a number as hex digits into a buffer. */
#include "test.h"

char out[9];
NOINLINE void fmt(unsigned v) { for (int i = 7; i >= 0; i--) { unsigned d = v & 0xFu; out[i] = (char)(d < 10u ? '0' + d : 'a' + d - 10u); v >>= 4; } out[8] = 0; }
int test_call(void) { fmt(0x00c0ffeeu); return out[2] * 1000 + out[7]; }

// RUN: test_call = 99101
