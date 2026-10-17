/* A function pointer stored in a modifiable global. */
#include "test.h"

NOINLINE int inc(int x) { return x + 1; }
NOINLINE int dec(int x) { return x - 1; }
int (*handler)(int) = inc;
NOINLINE int run(int x) { return handler(x); }
int test_default(void) { handler = inc; return run(10); }
int test_changed(void) { handler = dec; return run(10); }

// RUN: test_default = 11
// RUN: test_changed = 9
