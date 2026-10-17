/* A tail-recursive function (subtraction GCD). */
#include "test.h"

NOINLINE unsigned gcd(unsigned a, unsigned b) { return b == 0 ? a : a > b ? gcd(a - b, b) : gcd(a, b - a); }
int test_a(void) { return (int)gcd(48u, 18u); }
int test_b(void) { return (int)gcd(17u, 5u); }

// RUN: test_a = 6
// RUN: test_b = 1
