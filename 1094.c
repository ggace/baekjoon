#include <stdio.h>

int main() {
    int X;

    scanf("%d", &X);

    int result = 0;

    for(int i = 0; i < 7; i++){
        result += X & 1;
        X = X >> 1;
    }

    printf("%d\n", result);
}