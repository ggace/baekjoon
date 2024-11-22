#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;

    if(a + b - 1 > 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }

    printf("%d\n", a & b);


    return 0;
}