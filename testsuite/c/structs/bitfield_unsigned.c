/* Reading and writing unsigned bitfields. */
#include "test.h"

struct flags { unsigned a : 3; unsigned b : 5; unsigned c : 8; };
NOINLINE int f(int x, int y, int z) { struct flags fl; fl.a = x; fl.b = y; fl.c = z; return fl.a * 10000 + fl.b * 100 + fl.c; }
int test_call(void) { return f(5, 17, 99); }

// RUN: test_call = 51799
