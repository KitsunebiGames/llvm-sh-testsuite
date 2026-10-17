/* Store to a global variable. */
#include "test.h"

int g;

NOINLINE void f(void) { g = 48; }

int test_f(void) { f(); return g; }

// RUN: test_f = 48
