/* Parsing a decimal number from a string (atoi-like). */
#include "test.h"

NOINLINE int parse(const char *s) { int neg = 0, v = 0; if (*s == '-') { neg = 1; s++; } while (*s >= '0' && *s <= '9') v = v * 10 + (*s++ - '0'); return neg ? -v : v; }
int test_pos(void) { return parse("12345"); }
int test_neg(void) { return parse("-907"); }

// RUN: test_pos = 12345
// RUN: test_neg = -907
