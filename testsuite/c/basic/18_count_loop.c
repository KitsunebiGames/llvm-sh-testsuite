/* Simple counting loop (unsigned compares). */
#include "test.h"

NOINLINE unsigned f(unsigned n, unsigned d) {
    unsigned q = 0;
    while (n >= d) { n -= d; q++; }
    return q;
}

int test_17_5(void) { return f(17, 5); }
int test_5_5(void)  { return f(5, 5); }
int test_3_5(void)  { return f(3, 5); }

// RUN: test_17_5 = 3
// RUN: test_5_5 = 1
// RUN: test_3_5 = 0
