#define true 1;
#define false 0;
typedef long long ll;
typedef int bool;

#include <stdio.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

int gcd(int x, int y) {
    if(!(x % y)) {
        return y;
    }

    return gcd(y, x%y);
}

int main() {

    int a,b,c,d;

    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    
    int son = a * d + c * b;
    int mom = b * d;

    int g = gcd(son , mom);
    printf("%d %d\n", son/g, mom/g);

    return 0;
}