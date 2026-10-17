/* A typedef'd integer type. */
#include "test.h"

typedef unsigned short u16;
NOINLINE u16 f(u16 a) { return (u16)(a * 3u); }
int test_call(void) { return f(30000); }

// RUN: test_call = 24464
