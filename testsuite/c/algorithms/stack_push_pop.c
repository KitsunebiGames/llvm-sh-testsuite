/* An array-based stack. */
#include "test.h"

static int stack[8]; static int top;
NOINLINE void push(int v) { stack[top++] = v; }
NOINLINE int pop(void) { return stack[--top]; }
int test_call(void) { top = 0; push(1); push(2); push(3); int a = pop(); push(4); return a * 100 + pop() * 10 + pop(); }

// RUN: test_call = 342
