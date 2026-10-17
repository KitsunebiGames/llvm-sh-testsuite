/* Reading and writing several globals in one function. */
#include "test.h"

int ga = 5, gb = 6; short gc = 7;
NOINLINE int f(void) { ga += gb; gb = gc * 2; return ga * 100 + gb; }
int test_call(void) { return f(); }

// RUN: test_call = 1114
