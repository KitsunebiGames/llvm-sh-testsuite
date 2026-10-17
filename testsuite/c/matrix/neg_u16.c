/* Negation of a unsigned short argument. */
#include "test.h"

NOINLINE unsigned short f(unsigned short a) { return -a; }

int test_neg_0(void) { return f(1); }

// RUN: test_neg_0 = 65535
