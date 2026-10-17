/* The greatest common divisor by repeated subtraction. */
#include "test.h"

NOINLINE unsigned gcd(unsigned a, unsigned b) { while (a != b) { if (a > b) a -= b; else b -= a; } return a; }
int test_call(void) { return (int)gcd(1071u, 462u); }

// RUN: test_call = 21
