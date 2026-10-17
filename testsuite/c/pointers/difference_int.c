/* Subtracting two int pointers (element count). */
#include "test.h"

int arr[10];
NOINLINE int f(int *a, int *b) { return (int)(b - a); }
int test_call(void) { return f(&arr[2], &arr[9]); }

// RUN: test_call = 7
