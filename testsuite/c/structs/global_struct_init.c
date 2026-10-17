/* An initialised global struct. */
#include "test.h"

struct cfg { int w; short h; char depth; };
struct cfg screen = { 640, 480, 16 };
NOINLINE int f(void) { return screen.w + screen.h + screen.depth; }
int test_call(void) { return f(); }

// RUN: test_call = 1136
