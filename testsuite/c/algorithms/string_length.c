/* Computing the length of a string. */
#include "test.h"

NOINLINE int len(const char *s) { const char *p = s; while (*p) p++; return (int)(p - s); }
int test_call(void) { return len("Dreamcast!"); }

// RUN: test_call = 10
