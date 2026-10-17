/* A global array of string pointers. */
#include "test.h"

const char *names[3] = { "zero", "one", "two" };
NOINLINE int f(int i, int j) { return names[i][j]; }
int test_call(void) { return f(2, 1); }

// RUN: test_call = 119
