/* Two mutually recursive functions. */
#include "test.h"

NOINLINE int is_odd(int n);
NOINLINE int is_even(int n) { return n == 0 ? 1 : is_odd(n - 1); }
NOINLINE int is_odd(int n) { return n == 0 ? 0 : is_even(n - 1); }
int test_10(void) { return is_even(10) * 10 + is_odd(10); }
int test_7(void) { return is_even(7) * 10 + is_odd(7); }

// RUN: test_10 = 10
// RUN: test_7 = 1
