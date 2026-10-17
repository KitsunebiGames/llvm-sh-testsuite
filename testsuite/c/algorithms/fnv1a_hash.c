/* The 32-bit FNV-1a hash. */
#include "test.h"

NOINLINE unsigned fnv(const char *s) { unsigned h = 2166136261u; while (*s) { h ^= (unsigned char)*s++; h *= 16777619u; } return h; }
int test_call(void) { return (int)fnv("dreamcast"); }

// RUN: test_call = 441592019
