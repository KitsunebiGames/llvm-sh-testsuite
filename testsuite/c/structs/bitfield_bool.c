/* A one-bit _Bool bitfield. */
#include "test.h"

struct s { _Bool on : 1; unsigned rest : 7; };
NOINLINE int f(int v) { struct s x = { 0, 3 }; x.on = v; return x.on * 10 + x.rest; }
int test_true(void) { return f(5); }
int test_false(void) { return f(0); }

// RUN: test_true = 13
// RUN: test_false = 3
