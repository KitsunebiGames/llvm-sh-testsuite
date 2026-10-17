/* Inserting a value into a bit field. */
#include "test.h"

NOINLINE unsigned insert(unsigned x, unsigned v, int pos, int len) { unsigned m = ((1u << len) - 1u) << pos; return (x & ~m) | ((v << pos) & m); }
int test_call(void) { return insert(0xFFFFFFFFu, 0x5u, 8, 4) == 0xFFFFF5FFu; }

// RUN: test_call = 1
