/* Reading a misaligned field of a packed struct. */
#include "test.h"

struct __attribute__((packed)) p { char c; int i; short s; };
struct p data = { 1, 0x12345678, -2 };
NOINLINE int f(struct p *x) { return x->i + x->s; }
int test_call(void) { return f(&data); }

// RUN: test_call = 305419894
