/* Sign-extending a 12-bit value held in an int. */
#include "test.h"

NOINLINE int sext12(unsigned x) { return (int)(x << 20) >> 20; }
int test_neg(void) { return sext12(0xFFFu); }
int test_pos(void) { return sext12(0x7FFu); }

// RUN: test_neg = -1
// RUN: test_pos = 2047
