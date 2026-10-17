/* Loading a short through a pointer (sign extension). */
#include "test.h"

short s = -30000;
NOINLINE int f(const short *p) { return *p; }
int test_load(void) { return f(&s); }

// RUN: test_load = -30000
