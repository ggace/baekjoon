#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

#define rest 1000000007



ll my_pow(int n, int k) {
    if(k == 0) {
        return 1;
    }
    ll p = my_pow(n, k / 2) % rest;
    if(k % 2) {
        return (((p*p) % rest)*(n % rest)) % rest;
    }
    else {
        return (p * p) % rest;
    }
}

int main(int argc, char* argv[]) {
    //fio;    

    int n, k;

    cin >> n >> k;

    ll n_factorial = 1;
    ll a = 1;

    for(int i = 1; i <= n; i++) {
        n_factorial = ((n_factorial % rest) * (i % rest)) % rest;
    }

    for(int i = 1; i <= n-k; i++) {
        a = ((a%rest) * (i%rest)) % rest;
    }
    for(int i = 1; i <= k; i++) {
        a = ((a % rest) * (i % rest)) % rest;
    }

    int a_p = my_pow(a, rest-2);

    cout << ((n_factorial % rest) * (a_p % rest)) % rest << "\n";

    return 0;
}
