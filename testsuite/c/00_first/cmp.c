#include "test.h"

NOINLINE int i32_eq(int a, int b) { return a == b; }
NOINLINE int i32_ne(int a, int b) { return a != b; }
NOINLINE int i32_gt(int a, int b) { return a > b; }
NOINLINE int i32_ge(int a, int b) { return a >= b; }
NOINLINE int i32_lt(int a, int b) { return a < b; }
NOINLINE int i32_le(int a, int b) { return a <= b; }
NOINLINE int i32_nz(int a) { return a != 0; }
NOINLINE int i32_no(int a) { return a != 1; }
NOINLINE int  i32_z(int a) { return a == 0; }
NOINLINE int  i32_o(int a) { return a == 1; }

int i32_eq1() { return i32_eq(24, 24); }
int i32_eq2() { return i32_eq(21, 42); }
int i32_ne1() { return i32_ne(21, 42); }
int i32_ne2() { return i32_ne(24, 24); }
int i32_gt1() { return i32_gt(2, 0); }
int i32_gt2() { return i32_gt(0, 2); }
int i32_ge1() { return i32_ge(2, 2); }
int i32_ge2() { return i32_ge(3, 2); }
int i32_ge3() { return i32_ge(1, 2); }
int i32_lt1() { return i32_lt(0, 2); }
int i32_lt2() { return i32_lt(2, 0); }
int i32_le1() { return i32_le(2, 2); }
int i32_le2() { return i32_le(1, 2); }
int i32_le3() { return i32_le(3, 2); }
int i32_nz1() { return i32_nz(1); }
int i32_nz2() { return i32_nz(0); }
int i32_no1() { return i32_no(0); }
int i32_no2() { return i32_no(1); }
int i32_z1()  { return i32_z(0); }
int i32_z2()  { return i32_z(1); }
int i32_o1()  { return i32_o(1); }
int i32_o2()  { return i32_o(0); }

// RUN: i32_eq1 = 1
// RUN: i32_eq2 = 0
// RUN: i32_ne1 = 1
// RUN: i32_ne2 = 0
// RUN: i32_gt1 = 1
// RUN: i32_gt2 = 0
// RUN: i32_ge1 = 1
// RUN: i32_ge2 = 1
// RUN: i32_ge3 = 0
// RUN: i32_lt1 = 1
// RUN: i32_lt2 = 0
// RUN: i32_le1 = 1
// RUN: i32_le2 = 1
// RUN: i32_le3 = 0
// RUN: i32_nz1 = 1
// RUN: i32_nz2 = 0
// RUN: i32_no1 = 1
// RUN: i32_no2 = 0
// RUN: i32_z1 = 1
// RUN: i32_z2 = 0
// RUN: i32_o1 = 1
// RUN: i32_o2 = 0

NOINLINE int i16_eq(short a, short b) { return a == b; }
NOINLINE int i16_ne(short a, short b) { return a != b; }
NOINLINE int i16_gt(short a, short b) { return a > b; }
NOINLINE int i16_ge(short a, short b) { return a >= b; }
NOINLINE int i16_lt(short a, short b) { return a < b; }
NOINLINE int i16_le(short a, short b) { return a <= b; }
NOINLINE int i16_nz(short a) { return a != 0; }
NOINLINE int i16_no(short a) { return a != 1; }
NOINLINE int  i16_z(short a) { return a == 0; }
NOINLINE int  i16_o(short a) { return a == 1; }

int i16_eq1() { return i16_eq(24, 24); }
int i16_eq2() { return i16_eq(21, 42); }
int i16_ne1() { return i16_ne(21, 42); }
int i16_ne2() { return i16_ne(24, 24); }
int i16_gt1() { return i16_gt(2, 0); }
int i16_gt2() { return i16_gt(0, 2); }
int i16_ge1() { return i16_ge(2, 2); }
int i16_ge2() { return i16_ge(3, 2); }
int i16_ge3() { return i16_ge(1, 2); }
int i16_lt1() { return i16_lt(0, 2); }
int i16_lt2() { return i16_lt(2, 0); }
int i16_le1() { return i16_le(2, 2); }
int i16_le2() { return i16_le(1, 2); }
int i16_le3() { return i16_le(3, 2); }
int i16_nz1() { return i16_nz(1); }
int i16_nz2() { return i16_nz(0); }
int i16_no1() { return i16_no(0); }
int i16_no2() { return i16_no(1); }
int i16_z1()  { return i16_z(0); }
int i16_z2()  { return i16_z(1); }
int i16_o1()  { return i16_o(1); }
int i16_o2()  { return i16_o(0); }

// RUN: i16_eq1 = 1
// RUN: i16_eq2 = 0
// RUN: i16_ne1 = 1
// RUN: i16_ne2 = 0
// RUN: i16_gt1 = 1
// RUN: i16_gt2 = 0
// RUN: i16_ge1 = 1
// RUN: i16_ge2 = 1
// RUN: i16_ge3 = 0
// RUN: i16_lt1 = 1
// RUN: i16_lt2 = 0
// RUN: i16_le1 = 1
// RUN: i16_le2 = 1
// RUN: i16_le3 = 0
// RUN: i16_nz1 = 1
// RUN: i16_nz2 = 0
// RUN: i16_no1 = 1
// RUN: i16_no2 = 0
// RUN: i16_z1 = 1
// RUN: i16_z2 = 0
// RUN: i16_o1 = 1
// RUN: i16_o2 = 0

NOINLINE int i8_eq(char a, char b) { return a == b; }
NOINLINE int i8_ne(char a, char b) { return a != b; }
NOINLINE int i8_gt(char a, char b) { return a > b; }
NOINLINE int i8_ge(char a, char b) { return a >= b; }
NOINLINE int i8_lt(char a, char b) { return a < b; }
NOINLINE int i8_le(char a, char b) { return a <= b; }
NOINLINE int i8_nz(char a) { return a != 0; }
NOINLINE int i8_no(char a) { return a != 1; }
NOINLINE int  i8_z(char a) { return a == 0; }
NOINLINE int  i8_o(char a) { return a == 1; }

int i8_eq1() { return i8_eq(24, 24); }
int i8_eq2() { return i8_eq(21, 42); }
int i8_ne1() { return i8_ne(21, 42); }
int i8_ne2() { return i8_ne(24, 24); }
int i8_gt1() { return i8_gt(2, 0); }
int i8_gt2() { return i8_gt(0, 2); }
int i8_ge1() { return i8_ge(2, 2); }
int i8_ge2() { return i8_ge(3, 2); }
int i8_ge3() { return i8_ge(1, 2); }
int i8_lt1() { return i8_lt(0, 2); }
int i8_lt2() { return i8_lt(2, 0); }
int i8_le1() { return i8_le(2, 2); }
int i8_le2() { return i8_le(1, 2); }
int i8_le3() { return i8_le(3, 2); }
int i8_nz1() { return i8_nz(1); }
int i8_nz2() { return i8_nz(0); }
int i8_no1() { return i8_no(0); }
int i8_no2() { return i8_no(1); }
int i8_z1()  { return i8_z(0); }
int i8_z2()  { return i8_z(1); }
int i8_o1()  { return i8_o(1); }
int i8_o2()  { return i8_o(0); }

// RUN: i8_eq1 = 1
// RUN: i8_eq2 = 0
// RUN: i8_ne1 = 1
// RUN: i8_ne2 = 0
// RUN: i8_gt1 = 1
// RUN: i8_gt2 = 0
// RUN: i8_ge1 = 1
// RUN: i8_ge2 = 1
// RUN: i8_ge3 = 0
// RUN: i8_lt1 = 1
// RUN: i8_lt2 = 0
// RUN: i8_le1 = 1
// RUN: i8_le2 = 1
// RUN: i8_le3 = 0
// RUN: i8_nz1 = 1
// RUN: i8_nz2 = 0
// RUN: i8_no1 = 1
// RUN: i8_no2 = 0
// RUN: i8_z1 = 1
// RUN: i8_z2 = 0
// RUN: i8_o1 = 1
// RUN: i8_o2 = 0