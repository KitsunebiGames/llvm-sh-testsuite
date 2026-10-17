/* A struct field at a 1000-byte offset. */
#include "test.h"

struct huge { char pad[1000]; short x; };
struct huge h;
NOINLINE int f(struct huge *p) { p->x = -5; return p->x; }
int test_call(void) { return f(&h); }

// RUN: test_call = -5
