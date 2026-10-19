#include "test.h"

int factorial32(int n) {
	if (n == 0) return 1;
	else return n * factorial32(n-1);
}

int fact9_32() { return factorial32(9); }

// RUN: fact9_32 = 362880