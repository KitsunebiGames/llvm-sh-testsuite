/* Sign-extending an int to long long. */
#include "test.h"

NOINLINE long long f(int a) { return a; }
int test_call(void) { return (int)(f(-5) >> 32); }

// RUN: test_call = -1
