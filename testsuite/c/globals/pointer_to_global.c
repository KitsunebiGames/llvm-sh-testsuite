/* A global pointer initialised with another global's address (relocation). */
#include "test.h"

int target = 55;
int *ptr = &target;
NOINLINE int f(void) { return *ptr; }
int test_call(void) { return f(); }

// RUN: test_call = 55
