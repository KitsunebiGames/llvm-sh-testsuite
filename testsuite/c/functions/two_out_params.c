/* A function returning two results through pointers. */
#include "test.h"

NOINLINE void divmod8(unsigned x, unsigned *q, unsigned *r) { *q = x >> 3; *r = x & 7u; }
int test_call(void) { unsigned q, r; divmod8(83u, &q, &r); return (int)(q * 100 + r); }

// RUN: test_call = 1003
