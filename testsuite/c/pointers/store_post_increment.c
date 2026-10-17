/* Writing with *p++ = v. */
#include "test.h"

int arr[4];
NOINLINE void f(int *p) { *p++ = 1; *p++ = 2; *p++ = 3; *p = 4; }
int test_call(void) { f(arr); return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]; }

// RUN: test_call = 1234
