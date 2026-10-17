/* One function writing a global and another reading it. */
#include "test.h"

int shared;
NOINLINE void set(int v) { shared = v * 2; }
NOINLINE int get(void) { return shared + 1; }
int test_call(void) { set(20); return get(); }

// RUN: test_call = 41
