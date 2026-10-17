/* Reading through a pointer to a pointer. */
#include "test.h"

int x = 77; int *px = &x;
NOINLINE int f(int **pp) { return **pp; }
int test_call(void) { return f(&px); }

// RUN: test_call = 77
