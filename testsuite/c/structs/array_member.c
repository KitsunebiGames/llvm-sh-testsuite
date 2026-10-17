/* An array inside a struct. */
#include "test.h"

struct buf { int len; int data[4]; };
NOINLINE int f(struct buf *b) { int s = 0; for (int i = 0; i < b->len; i++) s += b->data[i]; return s; }
int test_call(void) { struct buf b = { 3, { 10, 20, 30, 40 } }; return f(&b); }

// RUN: test_call = 60
