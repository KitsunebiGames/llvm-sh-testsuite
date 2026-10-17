/* Converting a pointer to an integer and back. */
#include "test.h"

int x = 4321;
NOINLINE unsigned to_int(int *p) { return (unsigned)p; }
int test_call(void) { return *(int *)to_int(&x); }

// RUN: test_call = 4321
