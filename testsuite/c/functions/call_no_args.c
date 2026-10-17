/* Calling a function with no arguments. */
#include "test.h"

NOINLINE int seven(void) { return 7; }
int test_call(void) { return seven() + 1; }

// RUN: test_call = 8
