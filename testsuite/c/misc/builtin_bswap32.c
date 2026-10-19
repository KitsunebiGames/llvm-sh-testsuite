/* __builtin_bswap32. */
#include "test.h"

NOINLINE unsigned f(unsigned x) { return __builtin_bswap32(x); }
int test_call(void) { return f(0x11223344u) == 0x44332211u; }

// SKIP: test_call = 1
