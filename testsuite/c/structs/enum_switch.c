/* Switching on an enum. */
#include "test.h"

enum colour { RED, GREEN, BLUE };
NOINLINE int f(enum colour c) { switch (c) { case RED: return 0xf00; case GREEN: return 0x0f0; case BLUE: return 0x00f; } return 0; }
int test_green(void) { return f(GREEN); }
int test_blue(void) { return f(BLUE); }

// RUN: test_green = 240
// RUN: test_blue = 15
