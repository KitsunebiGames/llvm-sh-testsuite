/* Writing struct fields through a pointer. */
#include "test.h"

struct point { int x, y; };
NOINLINE void move(struct point *p, int dx, int dy) { p->x += dx; p->y += dy; }
int test_call(void) { struct point p = { 1, 2 }; move(&p, 10, 20); return p.x * 100 + p.y; }

// RUN: test_call = 1122
