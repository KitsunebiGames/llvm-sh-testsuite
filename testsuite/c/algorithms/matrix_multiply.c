/* Multiplying two 3x3 matrices. */
#include "test.h"

NOINLINE void mul(int c[3][3], const int a[3][3], const int b[3][3]) {
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) { int s = 0; for (int k = 0; k < 3; k++) s += a[i][k] * b[k][j]; c[i][j] = s; }
}
static const int ma[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }, mb[3][3] = { { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } };
static int mc[3][3];
int test_call(void) { mul(mc, ma, mb); return mc[0][0] + mc[1][1] * 1000 + mc[2][2] * 1000000; }

// RUN: test_call = 90069030
