/* Testing for a power of two with x & (x - 1). */
#include "test.h"

NOINLINE int pow2(unsigned x) { return x && !(x & (x - 1u)); }
int test_yes(void) { return pow2(4096u); }
int test_no(void) { return pow2(4097u); }

// RUN: test_yes = 1
// RUN: test_no = 0
