/* Loading an unsigned char through a pointer (zero extension). */
#include "test.h"

unsigned char c = 200;
NOINLINE int f(const unsigned char *p) { return *p; }
int test_load(void) { return f(&c); }

// RUN: test_load = 200
