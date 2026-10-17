/* A signed bitfield sign-extending on read. */
#include "test.h"

struct s { int v : 4; };
NOINLINE int f(int x) { struct s a; a.v = x; return a.v; }
int test_pos(void) { return f(7); }
int test_neg(void) { return f(-3); }

// RUN: test_pos = 7
// RUN: test_neg = -3
