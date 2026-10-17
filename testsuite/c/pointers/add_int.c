/* Adding an integer to an int pointer (scaled by 4). */
#include "test.h"

int arr[6] = { 0, 10, 20, 30, 40, 50 };
NOINLINE int f(int *p, int n) { return *(p + n); }
int test_3(void) { return f(arr, 3); }

// RUN: test_3 = 30
