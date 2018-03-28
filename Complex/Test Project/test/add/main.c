 #include "add.h"
#include <stdio.h>
//extern int add(int a, int b);

int main() {
    int a = 2;
    int b = 1;
    printf("a=%d, b=%d\n", a,b);
    printf("add: %d\n", add(a,b));
    getchar();
    return 0;
}