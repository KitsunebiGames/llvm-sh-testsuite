/* Converting a large unsigned value to int. */
#include "test.h"

NOINLINE int f(unsigned x) { return (int)x; }
int test_call(void) { return f(0xfffffffeu); }

// RUN: test_call = -2
