/* _Generic choosing by type. */
#include "test.h"

#define KIND(x) _Generic((x), char: 1, short: 2, int: 3, unsigned: 4, default: 0)
int test_call(void) { char c = 0; short s = 0; unsigned u = 0; return KIND(c) * 1000 + KIND(s) * 100 + KIND(1) * 10 + KIND(u); }

// RUN: test_call = 1234
