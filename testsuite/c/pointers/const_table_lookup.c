/* A lookup in a const (read-only) table. */
#include "test.h"

static const unsigned char squares[10] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
NOINLINE int f(int i) { return squares[i]; }
int test_9(void) { return f(9); }

// RUN: test_9 = 81
