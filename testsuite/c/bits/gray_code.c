/* Converting to and from Gray code. */
#include "test.h"

NOINLINE unsigned to_gray(unsigned x) { return x ^ (x >> 1); }
NOINLINE unsigned from_gray(unsigned g) { unsigned x = g; while (g >>= 1) x ^= g; return x; }
int test_to(void) { return (int)to_gray(13u); }
int test_round(void) { return (int)from_gray(to_gray(1234u)); }

// RUN: test_to = 11
// RUN: test_round = 1234
