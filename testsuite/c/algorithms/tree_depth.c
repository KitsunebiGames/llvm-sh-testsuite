/* Computing the depth of a binary tree. */
#include "test.h"

struct tree { struct tree *l, *r; };
struct tree t4 = { 0, 0 }, t3 = { &t4, 0 }, t2 = { 0, 0 }, t1 = { &t2, &t3 };
NOINLINE int depth(const struct tree *t) { if (!t) return 0; int a = depth(t->l), b = depth(t->r); return 1 + (a > b ? a : b); }
int test_call(void) { return depth(&t1); }

// RUN: test_call = 3
