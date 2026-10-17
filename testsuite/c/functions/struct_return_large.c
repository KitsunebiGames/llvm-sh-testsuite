/* Returning a 20-byte struct by value (hidden result pointer). */
#include "test.h"

struct five { int v[5]; };
NOINLINE struct five make(int x) { struct five f; for (int i = 0; i < 5; i++) f.v[i] = x + i; return f; }
int test_call(void) { struct five f = make(10); return f.v[0] + f.v[1] * 10 + f.v[4] * 100; }

// RUN: test_call = 1520
