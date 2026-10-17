#include "test.h"

short factorial16(short n) {
	if (n == 0) return 1;
	else return n * factorial16(n-1);
}

int factorial32(int n) {
	if (n == 0) return 1;
	else return n * factorial32(n-1);
}

int fact9_32() { return factorial32(9); }

// RUN: fact9_32 = 362880