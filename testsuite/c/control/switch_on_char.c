/* A switch on a char value. */
#include "test.h"

NOINLINE int f(char c) { switch (c) { case 'a': return 1; case 'z': return 26; case '0': return 100; default: return 0; } }
int test_a(void) { return f('a'); }
int test_z(void) { return f('z'); }
int test_0(void) { return f('0'); }
int test_other(void) { return f('Q'); }

// RUN: test_a = 1
// RUN: test_z = 26
// RUN: test_0 = 100
// RUN: test_other = 0
