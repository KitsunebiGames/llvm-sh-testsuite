/* Summing unsigned bytes above 127. */
#include "test.h"

unsigned char bytes[4] = { 200, 150, 255, 1 };
NOINLINE int f(const unsigned char *p, int n) { int s = 0; for (int i = 0; i < n; i++) s += p[i]; return s; }
int test_call(void) { return f(bytes, 4); }

// RUN: test_call = 606
