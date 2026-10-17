/* Reversing a linked list. */
#include "test.h"

struct node { int v; struct node *next; };
struct node d = { 4, 0 }, c = { 3, &d }, b = { 2, &c }, a = { 1, &b };
NOINLINE struct node *reverse(struct node *n) { struct node *prev = 0; while (n) { struct node *next = n->next; n->next = prev; prev = n; n = next; } return prev; }
int test_call(void) { struct node *h = reverse(&a); int s = 0; while (h) { s = s * 10 + h->v; h = h->next; } return s; }

// RUN: test_call = 4321
