/* An array of function pointers (dispatch table). */
#include "test.h"

NOINLINE int op_add(int a, int b) { return a + b; }
NOINLINE int op_sub(int a, int b) { return a - b; }
NOINLINE int op_mul(int a, int b) { return a * b; }
static int (*const ops[3])(int, int) = { op_add, op_sub, op_mul };
NOINLINE int apply(int i, int a, int b) { return ops[i](a, b); }
int test_add(void) { return apply(0, 6, 7); }
int test_sub(void) { return apply(1, 6, 7); }
int test_mul(void) { return apply(2, 6, 7); }

// RUN: test_add = 13
// RUN: test_sub = -1
// RUN: test_mul = 42
