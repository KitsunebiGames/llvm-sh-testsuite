/* Bitwise NOT of a unsigned int argument. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return ~a; }

int test_not_0(void) { return f(0u); }
int test_not_1(void) { return f(0x0f0f0f0fu); }

// RUN: test_not_0 = -1
// RUN: test_not_1 = -252645136
