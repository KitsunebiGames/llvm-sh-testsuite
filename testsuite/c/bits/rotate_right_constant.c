/* Rotating right by a constant amount. */
#include "test.h"

NOINLINE unsigned rotr8(unsigned x) { return (x >> 8) | (x << 24); }
int test_call(void) { return rotr8(0x12345678u) == 0x78123456u; }

// RUN: test_call = 1
