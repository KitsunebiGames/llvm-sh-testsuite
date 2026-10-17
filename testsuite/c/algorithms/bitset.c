/* A bitset in an array of words (set, clear, test). */
#include "test.h"

static unsigned bits[4];
NOINLINE void set(int i) { bits[i >> 5] |= 1u << (i & 31); }
NOINLINE void clr(int i) { bits[i >> 5] &= ~(1u << (i & 31)); }
NOINLINE int has(int i) { return (bits[i >> 5] >> (i & 31)) & 1u; }
int test_call(void) { set(3); set(40); set(127); clr(40); return has(3) * 100 + has(40) * 10 + has(127); }

// RUN: test_call = 101
