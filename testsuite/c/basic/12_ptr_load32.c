/* 32-bit load through a pointer argument. */
#include "test.h"

unsigned u = 0x1234;

NOINLINE unsigned f(const unsigned *p) { return *p; }

int test_f(void) { return f(&u); }

// RUN: test_f = 4660
