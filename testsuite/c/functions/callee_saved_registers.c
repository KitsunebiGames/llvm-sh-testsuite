/* Values kept live in registers across a call. */
#include "test.h"

NOINLINE int g(int x) { return x ^ 0x55; }
NOINLINE int f(int a) {
    int b = a + 1, c = a * 3, d = a - 7, e = a ^ 12, h = a << 2;
    int r = g(a);
    return r + b + c + d + e + h;
}
int test_call(void) { return f(100); }

// RUN: test_call = 1047
