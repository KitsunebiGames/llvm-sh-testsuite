/* Passing an 8-byte struct by value. */
#include "test.h"

struct pair { int a, b; };
NOINLINE int sum(struct pair p) { return p.a * 10 + p.b; }
int test_call(void) { struct pair p = { 4, 2 }; return sum(p); }

// RUN: test_call = 42
