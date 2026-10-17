/* Calling through a function pointer. */
#include "test.h"

NOINLINE int twice(int x) { return x * 2; }
NOINLINE int call(int (*fn)(int), int v) { return fn(v); }
int test_call(void) { return call(twice, 21); }

// RUN: test_call = 42
