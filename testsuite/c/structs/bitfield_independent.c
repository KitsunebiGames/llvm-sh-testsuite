/* Writing one bitfield not changing its neighbours. */
#include "test.h"

struct s { unsigned a : 4; unsigned b : 4; unsigned c : 4; };
NOINLINE int f(void) { struct s x = { 1, 2, 3 }; x.b = 15; return x.a * 100 + x.b * 10 + x.c; }
int test_call(void) { return f(); }

// RUN: test_call = 253
