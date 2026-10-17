/* Reversing an array in place with two pointers. */
#include "test.h"

int arr[5] = { 1, 2, 3, 4, 5 };
NOINLINE void rev(int *a, int n) { int *b = a + n - 1; while (a < b) { int t = *a; *a++ = *b; *b-- = t; } }
int test_call(void) { rev(arr, 5); return arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4]; }

// RUN: test_call = 54321
