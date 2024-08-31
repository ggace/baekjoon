#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef char bool;
#include <stdio.h>

ll min(ll a, ll b) {
    return a > b ? b : a;
}

int count;

int tmp[31][31] = {0, };

ll combination(int n, int r) {
    
    if(r == 1) {
        return n;
    }
    if(r == 0) {
        return 1;
    }
    //printf("%dC%d = %dC%d * %dC%d\n", n, r, n-1, min(r-1, n-r), n-1, min(r, n-1 -r) );
    //count++;
    int p = min(r-1, n-r);
    int q = min(r, n-r-1);
    if(!tmp[n-1][p])
        tmp[n-1][p] = combination(n-1, p);
    if(!tmp[n-1][q])
        tmp[n-1][q]= combination(n-1, q);
    return tmp[n][r] = tmp[n-1][p] + tmp[n-1][q];
}

int main(){

    int cases;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++){
        ll n, r;
        scanf("%lld %lld", &r, &n);
        printf("%lld\n", combination(n, min(r, n-r)));
    }

    return 0;
}