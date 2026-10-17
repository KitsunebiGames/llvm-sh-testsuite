/* Calling a static (internal linkage) function. */
#include "test.h"

static NOINLINE int helper(int x) { return x * 7; }
int test_call(void) { return helper(6); }

// RUN: test_call = 42
