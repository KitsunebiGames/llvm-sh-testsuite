/* Truncating int to unsigned short. */
#include "test.h"

NOINLINE unsigned short f(int x) { return (unsigned short)x; }

int test_0(void) { return (int)f(70000); }
int test_1(void) { return (int)f(-1); }

// RUN: test_0 = 4464
// RUN: test_1 = 65535
