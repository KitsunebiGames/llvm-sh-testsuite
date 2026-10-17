/* A struct nested inside another struct. */
#include "test.h"

struct inner { int a, b; };
struct outer { int x; struct inner in; int y; };
struct outer o = { 1, { 2, 3 }, 4 };
NOINLINE int f(struct outer *p) { return p->x * 1000 + p->in.a * 100 + p->in.b * 10 + p->y; }
int test_call(void) { return f(&o); }

// RUN: test_call = 1234
