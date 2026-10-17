/* Escapes inside string literals. */
#include "test.h"

NOINLINE int f(const char *s, int i) { return s[i]; }
int test_tab(void) { return f("a\tb", 1); }
int test_nul(void) { return f("x\0y", 2); }

// RUN: test_tab = 9
// RUN: test_nul = 121
