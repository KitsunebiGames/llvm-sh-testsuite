/* Short operands multiplied as int. */
#include "test.h"

NOINLINE int f(short a, short b) { return a * b; }
int test_call(void) { return f(300, 300); }

// RUN: test_call = 90000
