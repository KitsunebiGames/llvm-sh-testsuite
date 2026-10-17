/* A struct holding small fields that pack together. */
#include "test.h"

struct s { _Bool b; char c; unsigned char u; };
NOINLINE int f(struct s *p) { return p->b * 1000 + p->c + p->u; }
int test_call(void) { struct s x = { 1, -5, 250 }; return f(&x); }

// RUN: test_call = 1245
