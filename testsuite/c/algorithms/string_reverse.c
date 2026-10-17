/* Reversing a string in place. */
#include "test.h"

char text[] = "abcde";
NOINLINE void rev(char *s) { char *e = s; while (e[1]) e++; while (s < e) { char t = *s; *s++ = *e; *e-- = t; } }
int test_call(void) { rev(text); return text[0] * 1000 + text[4]; }

// RUN: test_call = 101097
