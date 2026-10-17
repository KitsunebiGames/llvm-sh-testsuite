/* A function returning a pointer to a global. */
#include "test.h"

static int store[4] = { 5, 6, 7, 8 };
NOINLINE int *at(int i) { return &store[i]; }
int test_call(void) { return *at(2) * 10 + *at(3); }

// RUN: test_call = 78
