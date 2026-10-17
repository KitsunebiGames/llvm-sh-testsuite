/* Plain char being signed. */
#include "test.h"

NOINLINE int f(char c) { return c < 0; }
int test_call(void) { return f((char)200); }

// RUN: test_call = 1
