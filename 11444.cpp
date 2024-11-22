#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

#define rest 1'000'000

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

ll n;

vector<vector<vector<ll>>> v;

vector<vector<ll>> djik_result = {{1,0}, {0,0}};

vector<vector<ll>> multiply_matix(vector<vector<ll>> a, vector<vector<ll>> b) {
    return {
        {
            (((a[0][0] * b[0][0]) % rest) + ((a[0][1] * b[1][0]) % rest)) % rest,
            (((a[0][0] * b[0][1]) % rest) + ((a[0][1] * b[1][1]) % rest)) % rest
        },
        {
            (((a[1][0] * b[0][0]) % rest) + ((a[1][1] * b[1][0]) % rest)) % rest,
            (((a[1][0] * b[0][1]) % rest) + ((a[1][1] * b[1][1]) % rest)) % rest
        }
    };
}

int main() {
    fio;

    cin >> n;

    if(n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    v.push_back({{1,1}, {1,0}});

    ll t = 1;
    for(ll i = 0; (t << i) <= n; i++) {
        //cout << i << " " << (t << i) << "\n";
        vector<vector<ll>> before_matrix = v[i];
        v.push_back(multiply_matix(before_matrix, before_matrix));
    }

    for(int i = 0; i < 64; i++) {
        if((n >> i) & 0b1) {
            djik_result = multiply_matix(v[i], djik_result);
        }
    }

    cout << djik_result[1][0] << "\n";

    return 0;
}