/* A loop with an empty body. */
#include "test.h"

NOINLINE int f(const char *s) { int i; for (i = 0; s[i] != '!'; i++) ; return i; }
int test_call(void) { return f("abc!"); }

// RUN: test_call = 3
