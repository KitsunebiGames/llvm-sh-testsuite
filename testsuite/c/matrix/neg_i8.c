/* Negation of a signed char argument. */
#include "test.h"

NOINLINE signed char f(signed char a) { return -a; }

int test_neg_0(void) { return f(5); }
int test_neg_1(void) { return f(-128); }

// RUN: test_neg_0 = -5
// RUN: test_neg_1 = -128
