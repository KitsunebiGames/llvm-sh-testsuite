/* A ring buffer with a power-of-two size and masked indices. */
#include "test.h"

static int ring[4]; static unsigned head, tail;
NOINLINE void put(int v) { ring[head++ & 3u] = v; }
NOINLINE int get(void) { return ring[tail++ & 3u]; }
int test_call(void) { head = tail = 0; for (int i = 1; i <= 6; i++) { put(i); if (i > 2) get(); } return get() * 10 + get(); }

// RUN: test_call = 56
