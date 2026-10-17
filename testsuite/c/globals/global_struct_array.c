/* An initialised global array of structs. */
#include "test.h"

struct kv { char key; int value; };
struct kv table[3] = { { 'a', 1 }, { 'b', 20 }, { 'c', 300 } };
NOINLINE int lookup(char k) { for (int i = 0; i < 3; i++) if (table[i].key == k) return table[i].value; return -1; }
int test_b(void) { return lookup('b'); }
int test_none(void) { return lookup('z'); }

// RUN: test_b = 20
// RUN: test_none = -1
