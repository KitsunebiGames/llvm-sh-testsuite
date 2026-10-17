/* Adding an integer to a short pointer (scaled by 2). */
#include "test.h"

short arr[5] = { 100, 200, 300, 400, 500 };
NOINLINE int f(short *p, int n) { return *(p + n); }
int test_2(void) { return f(arr, 2); }

// RUN: test_2 = 300
