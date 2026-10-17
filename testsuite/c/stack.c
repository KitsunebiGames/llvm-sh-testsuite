typedef struct MyStruct {
    int a;
    int b;
    int c;
    int d;
    int e;
} MyStruct;

int test(MyStruct s) {
    return s.a + s.b + s.c + s.d + s.e;
}

MyStruct make() {
    MyStruct s;
    s.a = 1;
    s.b = 2;
    s.c = 3;
    s.d = 4;
    s.e = 5;
    return s;
}

int stack_test() { return test(make()); }

// RUN: stack_test = 15