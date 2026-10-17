/* Comparing a function pointer against NULL. */
#include "test.h"

NOINLINE int id(int x) { return x; }
NOINLINE int maybe(int (*fn)(int), int v) { return fn ? fn(v) : -1; }
int test_set(void) { return maybe(id, 5); }
int test_null(void) { return maybe(0, 5); }

// RUN: test_set = 5
// RUN: test_null = -1
