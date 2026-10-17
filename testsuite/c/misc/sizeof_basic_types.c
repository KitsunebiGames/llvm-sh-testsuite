/* Sizeof for the basic integer and pointer types. */
#include "test.h"

int test_char(void) { return sizeof(char); }
int test_short(void) { return sizeof(short); }
int test_int(void) { return sizeof(int); }
int test_long(void) { return sizeof(long); }
int test_pointer(void) { return sizeof(void *); }
int test_long_long(void) { return sizeof(long long); }

// RUN: test_char = 1
// RUN: test_short = 2
// RUN: test_int = 4
// RUN: test_long = 4
// RUN: test_pointer = 4
// RUN: test_long_long = 8
