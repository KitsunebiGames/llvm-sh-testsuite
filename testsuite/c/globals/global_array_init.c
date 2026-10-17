/* An initialised global array. */
#include "test.h"

int primes[6] = { 2, 3, 5, 7, 11, 13 };
NOINLINE int f(void) { int s = 0; for (int i = 0; i < 6; i++) s += primes[i]; return s; }
int test_call(void) { return f(); }

// RUN: test_call = 41
