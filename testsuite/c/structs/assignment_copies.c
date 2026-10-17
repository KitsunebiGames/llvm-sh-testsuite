/* Struct assignment making an independent copy. */
#include "test.h"

struct trio { int a, b, c; };
NOINLINE int f(void) { struct trio x = { 1, 2, 3 }; struct trio y = x; y.b = 50; return x.b * 100 + y.b; }
int test_call(void) { return f(); }

// RUN: test_call = 250
