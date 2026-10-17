/* Finding a character in a string (strchr-like). */
#include "test.h"

NOINLINE int find(const char *s, char c) { for (int i = 0; s[i]; i++) if (s[i] == c) return i; return -1; }
int test_found(void) { return find("hitachi", 'c'); }
int test_missing(void) { return find("hitachi", 'z'); }

// RUN: test_found = 4
// RUN: test_missing = -1
