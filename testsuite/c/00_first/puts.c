/* Loop on a char condition (typical puts). */
#include "test.h"

const char *str = "hello";

static int count;

NOINLINE void putc_(char c) { (void)c; count++; }

NOINLINE void puts_(const char *s) { while (*s) putc_(*s++); }

int test_puts(void) { puts_(str); return count; }

// RUN: test_puts = 5
