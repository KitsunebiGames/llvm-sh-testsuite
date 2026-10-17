/* Negation of a unsigned int argument. */
#include "test.h"

NOINLINE unsigned f(unsigned a) { return -a; }

int test_neg_0(void) { return f(1u); }
int test_neg_1(void) { return f(0x80000000u); }

// RUN: test_neg_0 = -1
// RUN: test_neg_1 = -2147483648
