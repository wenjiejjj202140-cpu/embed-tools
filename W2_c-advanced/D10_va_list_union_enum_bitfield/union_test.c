#include <stdio.h>

union Test {
    char c;
    short s;
    int i;
};

int main() {
    union Test t;
    t.i = 0x12345678;
    printf("sizeof = %lu\n", sizeof(t));
    printf("c = 0x%x\n", t.c);
    printf("s = 0x%x\n", t.s);
    return 0;
}