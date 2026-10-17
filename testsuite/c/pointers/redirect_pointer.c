/* Changing which object a pointer points to via a pointer to it. */
#include "test.h"

int a = 1, b = 2;
NOINLINE void f(int **pp) { *pp = &b; }
int test_call(void) { int *p = &a; f(&p); return *p; }

// RUN: test_call = 2
