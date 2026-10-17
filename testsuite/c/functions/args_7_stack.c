/* 7 arguments, 3 of them passed on the stack. */
#include "test.h"

NOINLINE int f(int a0, int a1, int a2, int a3, int a4, int a5, int a6) { return a0 * 1 + a1 * 2 + a2 * 3 + a3 * 4 + a4 * 5 + a5 * 6 + a6 * 7; }
int test_call(void) { return f(10, 11, 12, 13, 14, 15, 16); }

// RUN: test_call = 392
