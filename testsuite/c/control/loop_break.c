/* Break leaving a loop early. */
#include "test.h"

static const int data[8] = { 4, 8, 15, 16, 23, 42, 7, 1 };
NOINLINE int find(int target) { int i; for (i = 0; i < 8; i++) if (data[i] == target) break; return i; }
int test_found(void) { return find(23); }
int test_missing(void) { return find(99); }

// RUN: test_found = 4
// RUN: test_missing = 8
