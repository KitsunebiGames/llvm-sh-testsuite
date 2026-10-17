/* The size of a union being its largest member. */
#include "test.h"

union u { char c; int i; short s[3]; };
int test_size(void) { return sizeof(union u); }

// RUN: test_size = 8
