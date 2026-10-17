/* Filling a byte array in a loop. */
#include "test.h"

unsigned char buf[16];
NOINLINE void fill(unsigned char *p, int n, unsigned char v) { while (n--) *p++ = v; }
int test_call(void) { fill(buf, 10, 7); return buf[0] + buf[9] + buf[10] * 100; }

// RUN: test_call = 14
