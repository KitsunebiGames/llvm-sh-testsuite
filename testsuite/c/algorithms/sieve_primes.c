/* Counting primes below 100 with a sieve. */
#include "test.h"

static unsigned char composite[100];
NOINLINE int count_primes(void) {
    int count = 0;
    for (int i = 0; i < 100; i++) composite[i] = 0;
    for (int i = 2; i < 100; i++) { if (composite[i]) continue; count++; for (int j = i + i; j < 100; j += i) composite[j] = 1; }
    return count;
}
int test_call(void) { return count_primes(); }

// RUN: test_call = 25
