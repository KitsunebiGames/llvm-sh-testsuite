/* Writing through a pointer to a pointer. */
#include "test.h"

int x;
NOINLINE void f(int **pp, int v) { **pp = v; }
int test_call(void) { int *p = &x; f(&p, 31); return x; }

// RUN: test_call = 31
