#define true 1;
#define false 0;
typedef long long ll;
typedef int bool;

#include <stdio.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

#define space 0
#define star 1

void go(int i, int j, int n) {
    if((i % n) * 3 / n == 1 && (j % n) * 3 / n == 1){
        printf(" ");
        return;
    }
    if(n == 1){
        printf("*");
        return;
    }

    go(i, j, n/3);

}

int main() {
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            go(i, j, n);
        }

        printf("\n");
    }

    

    return 0;
}