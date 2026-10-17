/* Reading each field of a struct with mixed field types. */
#include "test.h"

struct mixed { char c; short s; int i; unsigned char u; };
struct mixed m = { -3, -1000, 100000, 200 };
NOINLINE int f(struct mixed *p) { return p->c + p->s + p->i + p->u; }
int test_call(void) { return f(&m); }

// RUN: test_call = 99197
