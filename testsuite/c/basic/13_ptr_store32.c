/* 32-bit store through a pointer argument. */
#include "test.h"

unsigned v;

NOINLINE void f(unsigned *p) { *p = 0x30; }

int test_f(void) { f(&v); return v; }

// RUN: test_f = 48
