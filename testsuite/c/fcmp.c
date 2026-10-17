#include "test.h"

NOINLINE int eq(float a, float b) { return a == b; }
NOINLINE int ne(float a, float b) { return a != b; }
NOINLINE int gt(float a, float b) { return a > b; }
NOINLINE int ge(float a, float b) { return a >= b; }
NOINLINE int lt(float a, float b) { return a < b; }
NOINLINE int le(float a, float b) { return a <= b; }
NOINLINE int nz(float a) { return a != 0; }
NOINLINE int z(float a) { return a == 0; }

int test_eq1() { return eq(24, 24); }
int test_eq2() { return eq(21, 42); }
int test_ne1() { return ne(21, 42); }
int test_ne2() { return ne(24, 24); }
int test_gt1() { return gt(2, 0); }
int test_gt2() { return gt(0, 2); }
int test_ge1() { return ge(2, 2); }
int test_ge2() { return ge(3, 2); }
int test_ge3() { return ge(1, 2); }
int test_lt1() { return lt(0, 2); }
int test_lt2() { return lt(2, 0); }
int test_le1() { return le(2, 2); }
int test_le2() { return le(1, 2); }
int test_le3() { return le(3, 2); }
int test_z1() { return z(0); }
int test_z2() { return z(1); }
int test_nz1() { return nz(1); }
int test_nz2() { return nz(0); }

// XRUN: test_eq1 = 1
// XRUN: test_eq2 = 0
// XRUN: test_ne1 = 1
// XRUN: test_ne2 = 0
// XRUN: test_gt1 = 1
// XRUN: test_gt2 = 0
// XRUN: test_ge1 = 1
// XRUN: test_ge2 = 1
// XRUN: test_ge3 = 0
// XRUN: test_lt1 = 1
// XRUN: test_lt2 = 0
// XRUN: test_le1 = 1
// XRUN: test_le2 = 1
// XRUN: test_le3 = 0
// XRUN: test_z1 = 1
// XRUN: test_z2 = 0
// XRUN: test_nz1 = 1
// XRUN: test_nz2 = 0