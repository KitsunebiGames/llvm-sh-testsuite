/* An initialised global short. */
#include "test.h"

short gs = -1234;
NOINLINE int f(void) { return gs; }
int test_call(void) { return f(); }

// RUN: test_call = -1234
