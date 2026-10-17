/* Negation of a short argument. */
#include "test.h"

NOINLINE short f(short a) { return -a; }

int test_neg_0(void) { return f(1234); }
int test_neg_1(void) { return f(-32768); }

// RUN: test_neg_0 = -1234
// RUN: test_neg_1 = -32768
