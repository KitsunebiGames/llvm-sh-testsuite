/* More live values than registers across a call (spilling). */
#include "test.h"

NOINLINE int g(int x) { return x + 1; }
NOINLINE int f(int a) {
    int v0 = a + 1, v1 = a + 2, v2 = a + 3, v3 = a + 4, v4 = a + 5, v5 = a + 6, v6 = a + 7;
    int v7 = a + 8, v8 = a + 9, v9 = a + 10, v10 = a + 11, v11 = a + 12;
    int r = g(a);
    return r + v0 * 1 + v1 * 2 + v2 * 3 + v3 * 4 + v4 * 5 + v5 * 6 + v6 * 7 + v7 * 8 + v8 * 9 + v9 * 10 + v10 * 11 + v11 * 12;
}
int test_call(void) { return f(3); }

// RUN: test_call = 888
