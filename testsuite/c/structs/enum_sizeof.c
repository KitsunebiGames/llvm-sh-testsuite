/* The size of an enum type. */
#include "test.h"

enum e { X = 1, Y = 1000 };
int test_size(void) { return sizeof(enum e); }

// RUN: test_size = 4
