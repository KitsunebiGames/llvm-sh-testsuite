/* Passing a callback that the callee calls repeatedly. */
#include "test.h"

static int total;
NOINLINE void add_to_total(int v) { total += v; }
NOINLINE void each(int n, void (*cb)(int)) { for (int i = 1; i <= n; i++) cb(i); }
int test_call(void) { total = 0; each(10, add_to_total); return total; }

// RUN: test_call = 55
