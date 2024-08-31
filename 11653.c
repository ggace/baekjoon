#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

void go(int n){
    if(n == 1){
        return;
    }
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            printf("%d\n", i);
            go(n / i);
            break;
        }
    }
}

int main() {

    int n;

    scanf("%d", &n);

    go(n);
    
    return 0;
}