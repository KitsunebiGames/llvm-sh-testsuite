/* Transposing a 3x3 matrix in place. */
#include "test.h"

NOINLINE void transpose(int m[3][3]) { for (int i = 0; i < 3; i++) for (int j = i + 1; j < 3; j++) { int t = m[i][j]; m[i][j] = m[j][i]; m[j][i] = t; } }
static int m[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
int test_call(void) { transpose(m); return m[0][1] * 100 + m[2][0] * 10 + m[1][2]; }

// RUN: test_call = 438
