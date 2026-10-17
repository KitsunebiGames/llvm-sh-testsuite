/* Loop reading an array through a pointer. */
#include "test.h"

int arr[4] = {1, 2, 3, 4};

NOINLINE int sum(const int *a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

int test_sum4(void) { return sum(arr, 4); }
int test_sum0(void) { return sum(arr, 0); }

// RUN: test_sum4 = 10
// RUN: test_sum0 = 0
