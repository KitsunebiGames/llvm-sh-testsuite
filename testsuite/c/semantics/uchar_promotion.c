/* Unsigned char operands being promoted to int before adding. */
#include "test.h"

NOINLINE int f(unsigned char a, unsigned char b) { return a + b; }
int test_call(void) { return f(200, 100); }

// RUN: test_call = 300
