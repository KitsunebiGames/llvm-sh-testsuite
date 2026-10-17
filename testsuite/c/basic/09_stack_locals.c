/* Locals that must live on the stack (address taken). */
#include "test.h"

NOINLINE void use(int *p) { *p += 1; }

NOINLINE int f(int a) { int x = a; use(&x); return x; }

int test_f(void) { return f(5); }

// RUN: test_f = 6
