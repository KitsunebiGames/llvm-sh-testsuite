/* Integer power by repeated squaring. */
#include "test.h"

NOINLINE unsigned ipow(unsigned b, unsigned e) { unsigned r = 1; while (e) { if (e & 1u) r *= b; b *= b; e >>= 1; } return r; }
int test_3_13(void) { return (int)ipow(3u, 13u); }
int test_2_31(void) { return ipow(2u, 31u) == 0x80000000u; }

// RUN: test_3_13 = 1594323
// RUN: test_2_31 = 1
