/* The djb2 string hash (h * 33 + c). */
#include "test.h"

NOINLINE unsigned djb2(const char *s) { unsigned h = 5381u; while (*s) h = h * 33u + (unsigned char)*s++; return h; }
int test_call(void) { return (int)djb2("SuperH"); }

// RUN: test_call = -771781892
