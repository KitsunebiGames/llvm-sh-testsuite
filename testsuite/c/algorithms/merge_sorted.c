/* Merging two sorted arrays. */
#include "test.h"

NOINLINE void merge(int *out, const int *a, int na, const int *b, int nb) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) out[k++] = a[i] <= b[j] ? a[i++] : b[j++];
    while (i < na) out[k++] = a[i++];
    while (j < nb) out[k++] = b[j++];
}
int test_call(void) { int a[3] = { 1, 4, 9 }, b[3] = { 2, 3, 10 }, o[6]; merge(o, a, 3, b, 3); return o[0] * 100000 + o[1] * 10000 + o[2] * 1000 + o[3] * 100 + o[4] * 10 + (o[5] == 10); }

// RUN: test_call = 123491
