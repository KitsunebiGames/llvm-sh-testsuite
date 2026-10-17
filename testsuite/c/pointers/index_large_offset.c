/* Indexing a global array at a large byte offset. */
#include "test.h"

int big[600];
NOINLINE int f(int i) { big[i] = i * 3; return big[i] + big[i - 1]; }
int test_call(void) { return f(500); }

// RUN: test_call = 1500
