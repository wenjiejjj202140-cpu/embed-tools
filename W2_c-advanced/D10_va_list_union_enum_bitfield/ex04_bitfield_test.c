#include <stdio.h>

struct Packed {
    unsigned int a : 3;
    unsigned int b : 5;
    unsigned int c : 8;
};

int main() {
    struct Packed p;
    p.a = 8;   // 3 位最大是 7
    p.b = 31;
    p.c = 255;

    printf("sizeof = %lu\n", sizeof(p));
    printf("a = %u\n", p.a);
    printf("b = %u\n", p.b);
    printf("c = %u\n", p.c);
    return 0;
}
