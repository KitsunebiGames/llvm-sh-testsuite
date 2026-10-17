/* Load from a global variable. */
int g = 42;

int f(void) { return g; }

// RUN: f = 42
