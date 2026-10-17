/* Unsigned subtraction wrapping below zero. */
#include "test.h"

NOINLINE unsigned f(unsigned a, unsigned b) { return a - b; }
int test_call(void) { return f(0u, 1u) == 0xffffffffu; }

// RUN: test_call = 1
