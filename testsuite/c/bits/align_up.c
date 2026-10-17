/* Rounding up to a multiple of 16 with masks. */
#include "test.h"

NOINLINE unsigned align16(unsigned x) { return (x + 15u) & ~15u; }
int test_a(void) { return (int)align16(33u); }
int test_b(void) { return (int)align16(48u); }

// RUN: test_a = 48
// RUN: test_b = 48
