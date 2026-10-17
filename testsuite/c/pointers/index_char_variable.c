/* Indexing a char array with a variable. */
#include "test.h"

char str[] = "hello world";
NOINLINE int f(int i) { return str[i]; }
int test_6(void) { return f(6); }

// RUN: test_6 = 119
