int test(int a, int b, int c, int d, int e) {
	return a + b + c + d + e;
}

int test_args() { return test(1, 2, 3, 4, 5); }

// RUN: test_args = 15