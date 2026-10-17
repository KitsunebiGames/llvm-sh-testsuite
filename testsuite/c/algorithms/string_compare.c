/* Comparing two strings (strcmp-like). */
#include "test.h"

NOINLINE int cmp(const char *a, const char *b) { while (*a && *a == *b) { a++; b++; } return (unsigned char)*a - (unsigned char)*b; }
int test_equal(void) { return cmp("sega", "sega"); }
int test_less(void) { return cmp("sega", "segb") < 0; }
int test_prefix(void) { return cmp("seg", "sega") < 0; }

// RUN: test_equal = 0
// RUN: test_less = 1
// RUN: test_prefix = 1
