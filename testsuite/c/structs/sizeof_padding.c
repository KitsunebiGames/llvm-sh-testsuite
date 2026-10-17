/* Struct sizes including padding. */
#include "test.h"

struct a { char c; int i; };
struct b { char c; short s; };
struct c { char x, y, z; };
int test_a(void) { return sizeof(struct a); }
int test_b(void) { return sizeof(struct b); }
int test_c(void) { return sizeof(struct c); }

// RUN: test_a = 8
// RUN: test_b = 4
// RUN: test_c = 3
