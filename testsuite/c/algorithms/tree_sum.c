/* Summing a binary tree recursively. */
#include "test.h"

struct tree { int v; struct tree *l, *r; };
struct tree t4 = { 4, 0, 0 }, t5 = { 5, 0, 0 }, t2 = { 2, &t4, &t5 }, t3 = { 3, 0, 0 }, t1 = { 1, &t2, &t3 };
NOINLINE int sum(const struct tree *t) { return t ? t->v + sum(t->l) + sum(t->r) : 0; }
int test_call(void) { return sum(&t1); }

// RUN: test_call = 15
