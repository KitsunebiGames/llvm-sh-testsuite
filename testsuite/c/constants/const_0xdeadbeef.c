/* Returning the constant (int)0xdeadbeefu (materialisation of this value range). */
#include "test.h"

NOINLINE int f(void) { return (int)0xdeadbeefu; }

int test_value(void) { return f(); }

// RUN: test_value = -559038737
