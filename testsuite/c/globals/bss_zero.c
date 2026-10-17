/* An uninitialised global reading as zero. */
#include "test.h"

int zeroed[4];
NOINLINE int f(int i) { return zeroed[i]; }
int test_call(void) { return f(2) + 5; }

// RUN: test_call = 5
