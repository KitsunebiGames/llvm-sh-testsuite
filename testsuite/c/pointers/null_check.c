/* Checking a pointer against NULL. */
#include "test.h"

int x = 9;
NOINLINE int f(int *p) { return p ? *p : -1; }
int test_valid(void) { return f(&x); }
int test_null(void) { return f(0); }

// RUN: test_valid = 9
// RUN: test_null = -1
