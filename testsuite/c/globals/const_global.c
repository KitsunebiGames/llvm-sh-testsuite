/* A const global in read-only data. */
#include "test.h"

const int answer = 42;
NOINLINE int f(const int *p) { return *p; }
int test_call(void) { return f(&answer); }

// RUN: test_call = 42
