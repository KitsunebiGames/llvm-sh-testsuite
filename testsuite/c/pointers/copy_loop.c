/* Copying an array element by element. */
#include "test.h"

int src[5] = { 9, 8, 7, 6, 5 }; int dst[5];
NOINLINE void copy(int *d, const int *s, int n) { for (int i = 0; i < n; i++) d[i] = s[i]; }
int test_call(void) { copy(dst, src, 5); return dst[0] * 10000 + dst[2] * 100 + dst[4]; }

// RUN: test_call = 90705
