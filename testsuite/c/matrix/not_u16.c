/* Bitwise NOT of a unsigned short argument. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a) { return ~a; }

int test_not_0(void) { return f(0); }

// RUN: test_not_0 = 65535
