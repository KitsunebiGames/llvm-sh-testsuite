/* Taking the address of a struct member. */
#include "test.h"

struct s { int a, b, c; } obj = { 1, 2, 3 };
NOINLINE int f(int *p) { return *p; }
int test_call(void) { return f(&obj.c); }

// RUN: test_call = 3
