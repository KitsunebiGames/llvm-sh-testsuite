#include "test.h"

NOINLINE int eq(int a, int b) { return a == b; }
NOINLINE int ne(int a, int b) { return a != b; }
NOINLINE int gt(int a, int b) { return a > b; }
NOINLINE int ge(int a, int b) { return a >= b; }
NOINLINE int lt(int a, int b) { return a < b; }
NOINLINE int le(int a, int b) { return a <= b; }
NOINLINE int nz(int a) { return a != 0; }
NOINLINE int z(int a) { return a == 0; }
NOINLINE int no(int a) { return a != 1; }
NOINLINE int o(int a) { return a == 1; }
NOINLINE int ueq(unsigned a, unsigned b) { return a == b; }
NOINLINE int une(unsigned a, unsigned b) { return a != b; }
NOINLINE int ugt(unsigned a, unsigned b) { return a > b; }
NOINLINE int uge(unsigned a, unsigned b) { return a >= b; }
NOINLINE int ult(unsigned a, unsigned b) { return a < b; }
NOINLINE int ule(unsigned a, unsigned b) { return a <= b; }

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

int test_ueq1() { return ueq(1, 1); }
int test_ueq2() { return ueq(0, 1); }
int test_une1() { return une(1, 0); }
int test_une2() { return une(1, 1); }
int test_ugt1() { return ugt(1, 0); }
int test_ugt2() { return ugt(0, 1); }
int test_uge1() { return uge(1, 0); }
int test_uge2() { return uge(1, 1); }
int test_uge3() { return uge(0, 1); }
int test_ult1() { return ult(1, 2); }
int test_ult2() { return ult(2, 1); }
int test_ule1() { return ule(1, 2); }
int test_ule2() { return ule(2, 2); }
int test_ule3() { return ule(2, 1); }
int test_o1() { return o(1); }
int test_o2() { return o(0); }
int test_no1() { return no(0); }
int test_no2() { return no(1); }

// RUN: test_eq1 = 1
// RUN: test_eq2 = 0
// RUN: test_ne1 = 1
// RUN: test_ne2 = 0
// RUN: test_gt1 = 1
// RUN: test_gt2 = 0
// RUN: test_ge1 = 1
// RUN: test_ge2 = 1
// RUN: test_ge3 = 0
// RUN: test_lt1 = 1
// RUN: test_lt2 = 0
// RUN: test_le1 = 1
// RUN: test_le2 = 1
// RUN: test_le3 = 0
// RUN: test_z1 = 1
// RUN: test_z2 = 0
// RUN: test_nz1 = 1
// RUN: test_nz2 = 0

// RUN: test_ueq1 = 1
// RUN: test_ueq2 = 0
// RUN: test_une1 = 1
// RUN: test_une2 = 0
// RUN: test_ugt1 = 1
// RUN: test_ugt2 = 0
// RUN: test_uge1 = 1
// RUN: test_uge2 = 1
// RUN: test_uge3 = 0
// RUN: test_ult1 = 1
// RUN: test_ult2 = 0
// RUN: test_ule1 = 1
// RUN: test_ule2 = 1
// RUN: test_ule3 = 0
// RUN: test_o1 = 1
// RUN: test_o2 = 0
// RUN: test_no1 = 1
// RUN: test_no2 = 0