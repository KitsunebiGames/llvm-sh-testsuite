/* Bitwise NOT of a short argument. */
#include "test.h"

NOINLINE short f(short a) { return ~a; }

int test_not_0(void) { return f(0x1234); }

// RUN: test_not_0 = -4661
