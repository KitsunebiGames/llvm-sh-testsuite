/* Returning a unsigned char result that the caller widens to int. */
#include "test.h"

NOINLINE unsigned char f(int x) { return (unsigned char)(x + 1); }

int test_a(void) { return f(127) + 0; }
int test_b(void) { return f(255) + 0; }
int test_c(void) { return f(32767) + 0; }
int test_d(void) { return f(-2) + 0; }

// RUN: test_a = 128
// RUN: test_b = 0
// RUN: test_c = 0
// RUN: test_d = 255
