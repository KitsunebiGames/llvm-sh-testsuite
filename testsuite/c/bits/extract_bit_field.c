/* Extracting a bit field with shift and mask. */
#include "test.h"

NOINLINE unsigned field(unsigned x, int pos, int len) { return (x >> pos) & ((1u << len) - 1u); }
int test_call(void) { return (int)field(0xABCD1234u, 12, 8); }

// RUN: test_call = 209
