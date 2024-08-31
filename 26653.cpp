#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(int argc, char* argv[]) {
    fio;

    int n, m;

    cin >> n >> m;

    int t = 1;
    for(int i = 0; i < n; i++) {
        t *= 2;
    }
    int temp_t = t;

    ll p = 1, q = 1;
    for(int i = 0; i < m; i++) {
        p *= temp_t;
        q *= t;

        int g = gcd(p, q);
        p /= g;
        q /= g;

        cout << p << "/" << q << "\n";        

        temp_t -= 1;
    }

    cout << p << "/" << q << "\n";

    return 0;
}
