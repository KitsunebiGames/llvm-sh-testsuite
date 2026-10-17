/* A 16-bit store not disturbing the neighbouring elements. */
#include "test.h"

unsigned short buf[3] = { 1, 2, 3 };
NOINLINE void f(unsigned short *p) { p[1] = 0xBEEF; }
int test_store(void) { f(buf); return buf[0] + buf[2] * 10 + (buf[1] == 0xBEEF) * 100; }

// RUN: test_store = 131
