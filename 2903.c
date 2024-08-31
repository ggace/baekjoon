#define true 1;
#define false 0;
typedef long long ll;

#include <stdio.h>
#include <math.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

int main() {

    int n;

    scanf("%d", &n);

    printf("%d", (int)pow((int)pow(2, n) + 1, 2));
    
    return 0;
}