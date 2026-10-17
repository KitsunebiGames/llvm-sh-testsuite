/* Offsetof for fields after padding. */
#include "test.h"

struct s { char c; short h; int i; char d; };
int test_h(void) { return __builtin_offsetof(struct s, h); }
int test_i(void) { return __builtin_offsetof(struct s, i); }
int test_d(void) { return __builtin_offsetof(struct s, d); }
int test_size(void) { return sizeof(struct s); }

// RUN: test_h = 2
// RUN: test_i = 4
// RUN: test_d = 8
// RUN: test_size = 12
