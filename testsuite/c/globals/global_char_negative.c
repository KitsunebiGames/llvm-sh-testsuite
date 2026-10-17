/* An initialised global signed char holding a negative value. */
#include "test.h"

signed char gc = -77;
NOINLINE int f(void) { return gc; }
int test_call(void) { return f(); }

// RUN: test_call = -77
