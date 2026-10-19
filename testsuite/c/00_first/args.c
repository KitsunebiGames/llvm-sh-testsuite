int test(int a, int b, int c, int d, int e, int f) {
	return a + b + c + d + e + f;
}

int test_args() { return test(1, 2, 3, 4, 5, 6); }

// RUN: test_args = 21