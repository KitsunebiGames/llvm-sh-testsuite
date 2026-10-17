/* Comparing two structs field by field. */
#include "test.h"

struct p { int a; short b; char c; };
NOINLINE int eq(const struct p *x, const struct p *y) { return x->a == y->a && x->b == y->b && x->c == y->c; }
int test_same(void) { struct p a = { 1, 2, 3 }, b = { 1, 2, 3 }; return eq(&a, &b); }
int test_diff(void) { struct p a = { 1, 2, 3 }, b = { 1, 2, 4 }; return eq(&a, &b); }

// RUN: test_same = 1
// RUN: test_diff = 0
