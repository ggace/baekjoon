#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

ll m, a, c, x0, n, g;
ll rest;

vector<vector<vector<ll>>> v;
vector<vector<ll>> result;

vector<vector<ll>> multiply_matix(vector<vector<ll>> a, vector<vector<ll>> b) {
    
    return {
        {
            (ll)(((((__int128_t)a[0][0] * (__int128_t)b[0][0]) % rest) + (((__int128_t)a[0][1] * (__int128_t)b[1][0]) % rest)) % rest),
            (ll)(((((__int128_t)a[0][0] * (__int128_t)b[0][1]) % rest) + (((__int128_t)a[0][1] * (__int128_t)b[1][1]) % rest)) % rest)
        },
        {
            (ll)(((((__int128_t)a[1][0] * (__int128_t)b[0][0]) % rest) + (((__int128_t)a[1][1] * (__int128_t)b[1][0]) % rest)) % rest),
            (ll)(((((__int128_t)a[1][0] * (__int128_t)b[0][1]) % rest) + (((__int128_t)a[1][1] * (__int128_t)b[1][1]) % rest)) % rest)
        }
    };
}  

int main(int argc, char* argv[]) {
    fio;

    cin >> m >> a >> c >> x0 >> n >> g;
    rest = m;
    result = {{x0 % rest, 0}, {1, 0}};
    
    if(n == 0) {
        cout << x0 << "\n";
        return 0;
    }

    v.push_back({
        {a % rest, c % rest},
        {0, 1}
    });

    ll t = 1;
    for(ll i = 0; (t << i) <= n; i++) {
        //cout << i << " " << (t << i) << "\n";
        vector<vector<ll>> before_matrix = v[i];
        v.push_back(multiply_matix(before_matrix, before_matrix));
    }

    for(int i = 0; i < 64; i++) {
        if((n >> i) & 0b1) {
            //cout << v[i][0][0] << "\n";
            result = multiply_matix(v[i], result);
        }
    }


    //cout << result[0][0] << "\n";
    cout << (result[0][0] % g) << "\n";



    return 0;
}
