/* A struct initialised with designated initialisers. */
#include "test.h"

struct cfg { int a, b, c, d; };
NOINLINE int f(void) { struct cfg c = { .d = 4, .b = 2 }; return c.a * 1000 + c.b * 100 + c.c * 10 + c.d; }
int test_call(void) { return f(); }

// RUN: test_call = 204
