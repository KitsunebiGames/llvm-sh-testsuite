/* A global pointer to a string literal. */
#include "test.h"

const char *greeting = "hi!";
NOINLINE int f(int i) { return greeting[i]; }
int test_call(void) { return f(1) * 1000 + f(2); }

// RUN: test_call = 105033
