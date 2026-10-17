/* An array compound literal. */
#include "test.h"

NOINLINE int sum(const int *p, int n) { int s = 0; while (n--) s += *p++; return s; }
int test_call(void) { return sum((const int[]){ 10, 20, 30, 40 }, 4); }

// RUN: test_call = 100
