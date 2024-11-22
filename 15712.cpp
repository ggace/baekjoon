#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, i) for(i = a; i < b; i++) 
#define foreach(l, ele) for(ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

using namespace std;

ll fastpow(ll a, ll n, ll c){
    ll result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=c) result%=c;
        }
        a*=a;
        if(a>=c) a%=c;
        n>>=1;
    }
    return result;
}

vector<vector<vector<ll>>> v;
vector<vector<ll>> djik_result;
int rest;

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

int main(int argc, char* argv[]) {
    fio;

    ll a, r, n, m;

    cin >> a >> r >> n >> m;
    a %= m;
    r %= m;
    rest = m;
    v.push_back({
        {1,1},
        {0,r}
    });
    djik_result.push_back({a, 0});
    djik_result.push_back({(a*r)%m, 0});

    n--;
    ll t = 1;
    for(ll i = 0; (t << (i)) <= n; i++) {
        vector<vector<ll>> before_matrix = v[i];
        v.push_back(multiply_matix(before_matrix, before_matrix));
    }
    for(int i = 0; i < 64; i++) {
        if((n >> i) & 0b1) {
            djik_result = multiply_matix(v[i], djik_result);
            
        }
    }

    cout << djik_result[0][0] << "\n";


    

    return 0;
}
