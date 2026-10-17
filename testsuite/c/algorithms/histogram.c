/* Building a histogram of byte values. */
#include "test.h"

NOINLINE int hist(const unsigned char *p, int n) { int h[4] = { 0 }; for (int i = 0; i < n; i++) h[p[i] & 3]++; return h[0] * 1000 + h[1] * 100 + h[2] * 10 + h[3]; }
int test_call(void) { const unsigned char d[9] = { 0, 1, 2, 3, 4, 5, 6, 8, 12 }; return hist(d, 9); }

// RUN: test_call = 4221
