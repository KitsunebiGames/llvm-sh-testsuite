/* __builtin_expect not changing the result. */
#include "test.h"

NOINLINE int f(int x) { if (__builtin_expect(x > 0, 1)) return 1; return 2; }
int test_call(void) { return f(5) * 10 + f(-5); }

// SKIP: test_call = 12
