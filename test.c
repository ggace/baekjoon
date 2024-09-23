#include <stdio.h>

int main() {
    int i = 2;

    int a = i << 3;
    int b = i * 8;

    int c = 1 << 3;
    int d = 1 * 8;

    int result = a +b+c+d;

    printf("%d\n", result);
}