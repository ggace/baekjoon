#define true 1;
#define false 0;
typedef long long ll;

#include <stdio.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

int main() {
    int t;
    int c;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &c);
        int q = c / 25;
        c -= 25*q;
        int d = c / 10;
        c -= 10 * d;
        int n = c / 5;
        c -= 5 * n;
        int p = c;

        printf("%d %d %d %d\n", q, d, n, p);
    }
    return 0;
}