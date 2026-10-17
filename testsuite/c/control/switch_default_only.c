/* A switch containing only a default label. */
#include "test.h"

NOINLINE int f(int x) { switch (x) { default: return x + 1; } }
int test_a(void) { return f(41); }

// RUN: test_a = 42
