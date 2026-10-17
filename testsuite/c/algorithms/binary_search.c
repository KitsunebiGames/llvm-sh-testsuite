/* Binary search in a sorted array. */
#include "test.h"

static const int sorted[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
NOINLINE int search(int key) {
    int lo = 0, hi = 9;
    while (lo <= hi) { int mid = (lo + hi) >> 1; if (sorted[mid] == key) return mid; if (sorted[mid] < key) lo = mid + 1; else hi = mid - 1; }
    return -1;
}
int test_found(void) { return search(13); }
int test_missing(void) { return search(4); }

// RUN: test_found = 6
// RUN: test_missing = -1
