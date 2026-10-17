/* Bitwise NOT of a unsigned char argument. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a) { return ~a; }

int test_not_0(void) { return f(0); }
int test_not_1(void) { return f(0x0f); }

// RUN: test_not_0 = 255
// RUN: test_not_1 = 240
