/* Passing the address of a local array to another function. */
#include "test.h"

NOINLINE void fill(int *p) { p[0] = 11; p[1] = 22; p[2] = 33; }
NOINLINE int f(void) { int a[3]; fill(a); return a[0] + a[1] + a[2]; }
int test_call(void) { return f(); }

// RUN: test_call = 66
