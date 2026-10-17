/* Equality against a small immediate (fits cmp/eq #imm). */
#include "test.h"

NOINLINE int f(int a) { return a == 5; }

int test_a(void) { return f(5); }
int test_b(void) { return f(1000); }
int test_c(void) { return f(-200); }
int test_d(void) { return f(99); }

// RUN: test_a = 1
// RUN: test_b = 0
// RUN: test_c = 0
// RUN: test_d = 0
