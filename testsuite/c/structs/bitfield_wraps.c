/* A value too wide for an unsigned bitfield being truncated. */
#include "test.h"

struct s { unsigned v : 3; };
NOINLINE int f(unsigned x) { struct s a; a.v = x; return a.v; }
int test_9(void) { return f(9u); }

// RUN: test_9 = 1
