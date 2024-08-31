#include <stdio.h>

int main() {
    int A, B, n;

    scanf("%d %d %d", &A, &B, &n);

    A %= B;

    int temp = A;

    for(int i = 0; i < n; i++){
        A = temp * 10 / B;
        temp = (temp * 10) % B;
    }

    printf("%d\n", A);

    return 0;
}