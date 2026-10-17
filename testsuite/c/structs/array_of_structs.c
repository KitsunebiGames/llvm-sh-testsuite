/* Indexing an array of structs. */
#include "test.h"

struct item { short id; int value; };
struct item items[3] = { { 1, 100 }, { 2, 200 }, { 3, 300 } };
NOINLINE int f(int i) { return items[i].id * 1000 + items[i].value; }
int test_2(void) { return f(2); }

// RUN: test_2 = 3300
