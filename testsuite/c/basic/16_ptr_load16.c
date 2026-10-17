/* 16-bit zero-extending load through a pointer. */
#include "test.h"

unsigned short h = 0x31;

NOINLINE unsigned f(const unsigned short *p) { return *p & 0x20; }

int test_f(void) { return f(&h); }

// RUN: test_f = 32
