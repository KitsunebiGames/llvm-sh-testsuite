/* A byte store not disturbing the neighbouring bytes. */
#include "test.h"

unsigned char buf[4] = { 1, 2, 3, 4 };
NOINLINE void f(unsigned char *p) { p[1] = 0xAA; }
int test_store(void) { f(buf); return buf[0] + buf[1] * 10 + buf[2] * 10000 + buf[3] * 100000; }

// RUN: test_store = 431701
