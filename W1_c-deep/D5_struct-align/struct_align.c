#include <stdio.h>

typedef struct {
    char a;
    int  b;
    char c;
} Packed;

typedef struct {
    int  b;
    char a;
    char c;
} Packed2;

int main() {
    printf("Packed  : %zu 字节\n", sizeof(Packed));
    printf("Packed2 : %zu 字节\n", sizeof(Packed2));
    return 0;
}