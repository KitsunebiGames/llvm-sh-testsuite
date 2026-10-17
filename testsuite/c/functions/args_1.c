/* Passing one argument in r4. */
#include "test.h"

NOINLINE int f(int a) { return a * 3; }
int test_call(void) { return f(14); }

// RUN: test_call = 42
