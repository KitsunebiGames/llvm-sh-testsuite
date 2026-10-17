/* Basic 32-bit ALU operations on arguments. */
#include "test.h"

NOINLINE int      sub(int a, int b)            { return a - b; }
NOINLINE unsigned and_(unsigned a, unsigned b) { return a & b; }
NOINLINE unsigned or_(unsigned a, unsigned b)  { return a | b; }
NOINLINE unsigned xor_(unsigned a, unsigned b) { return a ^ b; }
NOINLINE int      neg(int a)                   { return -a; }

int test_sub(void) { return sub(10, 3); }
int test_and(void) { return and_(240, 60); }
int test_or(void)  { return or_(240, 15); }
int test_xor(void) { return xor_(255, 15); }
int test_neg(void) { return neg(5); }

// RUN: test_sub = 7
// RUN: test_and = 48
// RUN: test_or = 255
// RUN: test_xor = 240
// RUN: test_neg = -5
