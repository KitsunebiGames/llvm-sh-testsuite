/* A void function writing its result through a pointer. */
#include "test.h"

NOINLINE void f(int a, int *out) { *out = a * a; }
int test_call(void) { int r = 0; f(9, &r); return r; }

// RUN: test_call = 81
