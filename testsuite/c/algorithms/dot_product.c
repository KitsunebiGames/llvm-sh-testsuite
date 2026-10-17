/* The dot product of two vectors. */
#include "test.h"

NOINLINE int dot(const short *a, const short *b, int n) { int s = 0; for (int i = 0; i < n; i++) s += a[i] * b[i]; return s; }
int test_call(void) { short a[4] = { 1, -2, 300, 4 }, b[4] = { 5, 6, 7, -800 }; return dot(a, b, 4); }

// RUN: test_call = -1107
