/* Counting runs of equal values. */
#include "test.h"

NOINLINE int runs(const char *s) { int r = 0; char prev = 0; for (; *s; s++) if (*s != prev) { r++; prev = *s; } return r; }
int test_call(void) { return runs("aaabccddddde"); }

// RUN: test_call = 5
