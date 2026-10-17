/* Negation of a unsigned char argument. */
#include "test.h"

NOINLINE unsigned char f(unsigned char a) { return -a; }

int test_neg_0(void) { return f(5); }

// RUN: test_neg_0 = 251
