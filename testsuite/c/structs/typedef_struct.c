/* A typedef'd struct type. */
#include "test.h"

typedef struct { int w, h; } size_t2;
NOINLINE int area(size_t2 s) { return s.w * s.h; }
int test_call(void) { size_t2 s = { 12, 7 }; return area(s); }

// RUN: test_call = 84
