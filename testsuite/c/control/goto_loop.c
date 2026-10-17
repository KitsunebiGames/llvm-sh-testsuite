/* A loop written with a backward goto. */
#include "test.h"

NOINLINE int f(int n) { int s = 0, i = 0; again: if (i < n) { s += i; i++; goto again; } return s; }
int test_6(void) { return f(6); }

// RUN: test_6 = 15
