/* Reinterpreting signed char as unsigned char. */
#include "test.h"

NOINLINE int f(signed char x) { return (unsigned char)x; }

int test_0(void) { return (int)f(-56); }
int test_1(void) { return (int)f(100); }

// RUN: test_0 = 200
// RUN: test_1 = 100
