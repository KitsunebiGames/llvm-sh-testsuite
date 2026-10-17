/* 16-bit store through a pointer (truncstorei16). */
#include "test.h"

unsigned short h;

NOINLINE void f(unsigned short *p) { *p = 0x30; }

int test_f(void) { f(&h); return h; }

// RUN: test_f = 48
