/* Adding an integer to a char pointer (no scaling). */
#include "test.h"

char str[] = "abcdef";
NOINLINE int f(char *p, int n) { return *(p + n); }
int test_4(void) { return f(str, 4); }

// RUN: test_4 = 101
