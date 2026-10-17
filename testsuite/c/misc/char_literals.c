/* Character literals and escapes. */
#include "test.h"

int test_letter(void) { return 'A' + 1; }
int test_newline(void) { return '\n'; }
int test_hex_escape(void) { return '\x41'; }

// RUN: test_letter = 66
// RUN: test_newline = 10
// RUN: test_hex_escape = 65
