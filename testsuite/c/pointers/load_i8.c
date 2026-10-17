/* Loading a signed char through a pointer (sign extension). */
#include "test.h"

signed char c = -100;
NOINLINE int f(const signed char *p) { return *p; }
int test_load(void) { return f(&c); }

// RUN: test_load = -100
