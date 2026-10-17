int globalVar;
int test_globals() { globalVar++; globalVar++; return globalVar; }

// RUN: test_globals = 2