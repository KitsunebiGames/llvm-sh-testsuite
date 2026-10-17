/* A static local variable keeping its value between calls. */
#include "test.h"

NOINLINE int next(void) { static int count = 10; return count++; }
int test_call(void) { next(); next(); return next(); }

// RUN: test_call = 12
