/* Arguments of mixed widths (char, short, int, unsigned char). */
#include "test.h"

NOINLINE int f(signed char a, short b, int c, unsigned char d) { return a + b + c + d; }
int test_call(void) { return f(-5, -300, 100000, 250); }

// RUN: test_call = 99945
