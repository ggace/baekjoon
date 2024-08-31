#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(){
    fio;

    ll n, m, a;
    ll h;

    cin >> n >> m >> a;
    cin >> h;

    ll result = 1;
    for(int i = 0; i < n-1; i++) {
        result *= m;
        result %= 1000000007;
    }

    cout << result << "\n";


    return 0;
}
