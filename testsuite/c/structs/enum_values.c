/* Enum constants with implicit and explicit values. */
#include "test.h"

enum e { A, B, C = 10, D, E = -3, F };
int test_call(void) { return A + B * 10 + C * 100 + D * 1000 + E * 10000 + F; }

// RUN: test_call = -17992
