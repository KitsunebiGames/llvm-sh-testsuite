/* Reading with *++p. */
#include "test.h"

int arr[4] = { 3, 5, 7, 9 };
NOINLINE int f(int *p) { int a = *++p; int b = *++p; return a * 10 + b; }
int test_call(void) { return f(arr); }

// RUN: test_call = 57
