int shr(int a, int b) {
	return (unsigned)a >> b;
}

int shl(int a, int b) {
	return a << b;
}

int shar(int a, int b) {
	return (int)((long)a >> b);
}

int shr_test()  { return shr(8, 1); }
int shar_test() { return shar(8, 1); }
int shl_test()  { return shl(8, 1); }

// RUN: shr_test = 4
// RUN: shar_test = 4
// RUN: shl_test = 16
