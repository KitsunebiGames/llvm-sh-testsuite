/* A switch inside a loop (simple state machine). */
#include "test.h"

NOINLINE int f(int steps) {
    int state = 0, out = 0;
    for (int i = 0; i < steps; i++) {
        switch (state) { case 0: out += 1; state = 1; break; case 1: out += 10; state = 2; break; default: out += 100; state = 0; break; }
    }
    return out;
}
int test_7(void) { return f(7); }

// RUN: test_7 = 223
