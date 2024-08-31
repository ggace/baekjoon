#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int main() {
    ll arr[90] = {0,1};

    int n;

    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        arr[i+2] = arr[i] + arr[i+1];
    }

    printf("%lld", arr[n]);
    
    return 0;
}