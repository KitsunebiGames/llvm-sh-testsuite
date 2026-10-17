/* A struct compound literal. */
#include "test.h"

struct pair { int a, b; };
NOINLINE int sum(struct pair *p) { return p->a + p->b; }
int test_call(void) { return sum(&(struct pair){ 30, 12 }); }

// RUN: test_call = 42
