#include "test.h"

NOINLINE int eq(float a, float b) { return a == b; }
NOINLINE int ne(float a, float b) { return a != b; }
NOINLINE int gt(float a, float b) { return a > b; }
NOINLINE int ge(float a, float b) { return a >= b; }
NOINLINE int lt(float a, float b) { return a < b; }
NOINLINE int le(float a, float b) { return a <= b; }
NOINLINE int nz(float a) { return a != 0; }
NOINLINE int z(float a) { return a == 0; }

int i32_eq1() { return eq(24, 24); }
int i32_eq2() { return eq(21, 42); }
int i32_ne1() { return ne(21, 42); }
int i32_ne2() { return ne(24, 24); }
int i32_gt1() { return gt(2, 0); }
int i32_gt2() { return gt(0, 2); }
int i32_ge1() { return ge(2, 2); }
int i32_ge2() { return ge(3, 2); }
int i32_ge3() { return ge(1, 2); }
int i32_lt1() { return lt(0, 2); }
int i32_lt2() { return lt(2, 0); }
int i32_le1() { return le(2, 2); }
int i32_le2() { return le(1, 2); }
int i32_le3() { return le(3, 2); }
int i32_z1() { return z(0); }
int i32_z2() { return z(1); }
int i32_nz1() { return nz(1); }
int i32_nz2() { return nz(0); }

// SKIP: test_eq1 = 1
// SKIP: test_eq2 = 0
// SKIP: test_ne1 = 1
// SKIP: test_ne2 = 0
// SKIP: test_gt1 = 1
// SKIP: test_gt2 = 0
// SKIP: test_ge1 = 1
// SKIP: test_ge2 = 1
// SKIP: test_ge3 = 0
// SKIP: test_lt1 = 1
// SKIP: test_lt2 = 0
// SKIP: test_le1 = 1
// SKIP: test_le2 = 1
// SKIP: test_le3 = 0
// SKIP: test_z1 = 1
// SKIP: test_z2 = 0
// SKIP: test_nz1 = 1
// SKIP: test_nz2 = 0