/* Hex, octal and suffixed integer literals. */
#include "test.h"

int test_hex(void) { return 0x1F; }
int test_octal(void) { return 017; }
int test_unsigned(void) { return (int)(10u * 3u); }

// RUN: test_hex = 31
// RUN: test_octal = 15
// RUN: test_unsigned = 30
