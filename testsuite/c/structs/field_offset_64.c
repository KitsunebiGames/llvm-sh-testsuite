/* A struct field at byte offset 64 (beyond mov.l's @(disp,Rn) range). */
#include "test.h"

struct wide { int pad[16]; int x; };
struct wide w;
NOINLINE int f(struct wide *p) { p->x = 77; return p->x; }
int test_call(void) { return f(&w); }

// RUN: test_call = 77
