/* A static (file-scope) global variable. */
#include "test.h"

static int hidden = 3;
NOINLINE int bump(void) { hidden *= 3; return hidden; }
int test_call(void) { hidden = 3; bump(); return bump(); }

// RUN: test_call = 27
