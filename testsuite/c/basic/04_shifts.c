/* Constant and variable shifts (expanded via SHLri/SHRri/SRAri and the
 * SHLrr/SHRrr/SRArr loop pseudos). */
#include "test.h"

NOINLINE unsigned shl3(unsigned a)             { return a << 3; }
NOINLINE unsigned shr5(unsigned a)             { return a >> 5; }
NOINLINE int      sar7(int a)                  { return a >> 7; }
NOINLINE unsigned shlv(unsigned a, unsigned n) { return a << n; }
NOINLINE unsigned shrv(unsigned a, unsigned n) { return a >> n; }
NOINLINE int      sarv(int a, unsigned n)      { return a >> n; }

int test_shl3(void) { return shl3(5); }
int test_shr5(void) { return shr5(1024); }
int test_sar7(void) { return sar7(-1024); }
int test_shlv(void) { return shlv(3, 4); }
int test_shrv(void) { return shrv(256, 3); }
int test_sarv(void) { return sarv(-256, 4); }

// RUN: test_shl3 = 40
// RUN: test_shr5 = 32
// RUN: test_sar7 = -8
// RUN: test_shlv = 48
// RUN: test_shrv = 32
// RUN: test_sarv = -16
