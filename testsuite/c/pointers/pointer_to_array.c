/* A pointer to an array (int (*)[3]). */
#include "test.h"

int rows[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
NOINLINE int f(int (*p)[3], int i) { return p[i][2]; }
int test_call(void) { return f(rows, 1); }

// RUN: test_call = 6
