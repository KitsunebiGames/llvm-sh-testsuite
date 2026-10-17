/* A linear congruential random number generator. */
#include "test.h"

NOINLINE unsigned next(unsigned s) { return s * 1103515245u + 12345u; }
int test_call(void) { unsigned s = 1u; for (int i = 0; i < 5; i++) s = next(s); return (int)(s >> 16); }

// RUN: test_call = 63819
