/* An XOR checksum over a byte buffer. */
#include "test.h"

static const unsigned char data[8] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0 };
NOINLINE int sum(const unsigned char *p, int n) { unsigned char c = 0; while (n--) c ^= *p++; return c; }
int test_call(void) { return sum(data, 8); }

// RUN: test_call = 0
