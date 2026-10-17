/* Parsing a hexadecimal number from a string. */
#include "test.h"

NOINLINE unsigned parse(const char *s) { unsigned v = 0; for (;; s++) { char c = *s; if (c >= '0' && c <= '9') v = (v << 4) | (unsigned)(c - '0'); else if (c >= 'a' && c <= 'f') v = (v << 4) | (unsigned)(c - 'a' + 10); else break; } return v; }
int test_call(void) { return (int)parse("1f3a"); }

// RUN: test_call = 7994
