/* Setting, clearing and toggling individual bits. */
#include "test.h"

NOINLINE unsigned f(unsigned x) { x |= 1u << 5; x &= ~(1u << 1); x ^= 1u << 9; return x; }
int test_call(void) { return (int)f(0x0Fu); }

// RUN: test_call = 557
