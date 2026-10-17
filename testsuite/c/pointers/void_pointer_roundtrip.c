/* Converting through void * and back. */
#include "test.h"

int x = 1234;
NOINLINE void *hide(int *p) { return p; }
int test_call(void) { return *(int *)hide(&x); }

// RUN: test_call = 1234
