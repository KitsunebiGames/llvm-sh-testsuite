/* Subtracting two char pointers. */
#include "test.h"

char buf[40];
NOINLINE int f(char *a, char *b) { return (int)(b - a); }
int test_call(void) { return f(&buf[3], &buf[31]); }

// RUN: test_call = 28
