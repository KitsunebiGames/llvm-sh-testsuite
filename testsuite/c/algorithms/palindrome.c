/* Checking whether a string is a palindrome. */
#include "test.h"

NOINLINE int pal(const char *s, int n) { for (int i = 0, j = n - 1; i < j; i++, j--) if (s[i] != s[j]) return 0; return 1; }
int test_yes(void) { return pal("racecar", 7); }
int test_no(void) { return pal("racecars", 8); }

// RUN: test_yes = 1
// RUN: test_no = 0
