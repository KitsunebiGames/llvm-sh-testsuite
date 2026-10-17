/* Indexing a short array with a variable. */
#include "test.h"

short arr[6] = { -1, -2, -3, -4, -5, -6 };
NOINLINE int f(int i) { return arr[i]; }
int test_4(void) { return f(4); }

// RUN: test_4 = -5
