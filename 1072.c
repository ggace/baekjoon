#include <stdio.h>
#include <math.h>

int main() {
    long long X, Y;

    scanf("%lld %lld", &X, &Y);

    if(X == Y){
        printf("-1");
        return 0;
    }

    long long Z = (Y * 100) / X;

    if(Z == 99){
        printf("-1");
        return 0;
    }

    long long result = ceil((X * Z + X - 100 * Y) / (99. - Z));

    printf("%lld", result);

    return 0;
}