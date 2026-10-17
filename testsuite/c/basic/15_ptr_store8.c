/* 8-bit store through a pointer (truncstorei8). */
#include "test.h"

char c;

NOINLINE void f(char *p) { *p = 1; }

int test_f(void) { f(&c); return c; }

// RUN: test_f = 1
