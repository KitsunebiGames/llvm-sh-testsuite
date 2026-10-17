/* An initialised global unsigned char above 127. */
#include "test.h"

unsigned char gu = 222;
NOINLINE int f(void) { return gu; }
int test_call(void) { return f(); }

// RUN: test_call = 222
