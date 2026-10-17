/* A struct containing a pointer to its own type. */
#include "test.h"

struct node { int v; struct node *next; };
struct node n3 = { 3, 0 }, n2 = { 2, &n3 }, n1 = { 1, &n2 };
NOINLINE int f(struct node *n) { int s = 0; while (n) { s = s * 10 + n->v; n = n->next; } return s; }
int test_call(void) { return f(&n1); }

// RUN: test_call = 123
