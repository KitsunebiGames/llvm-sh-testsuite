/* Returning an 8-byte struct by value. */
#include "test.h"

struct pair { int a, b; };
NOINLINE struct pair make(int x) { struct pair p = { x, x * 2 }; return p; }
int test_call(void) { struct pair p = make(21); return p.a * 1000 + p.b; }

// RUN: test_call = 21042
