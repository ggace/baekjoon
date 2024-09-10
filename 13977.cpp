#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b) for(int i = a; i < b; i++) 
#define foreach(l) for(auto ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

using namespace std;

#define REST 1000000007

ll binary[20] = {1};
ll factorials[4000000 + 1] = {1};

ll my_pow(ll a, ll b) {
    ll result = 1;
    ll temp_bin = 2;
    binary[1] = a;
    for(int i = 2; temp_bin <= b; i++) {

        binary[i] = ( (binary[i-1] % REST) * (binary[i-1] % REST) ) % REST;

        temp_bin *= 2;
    }

    for(int i = 1; b != 0; i++) {
        if(b & 1) {
            
            result = ( (result % REST) * (binary[i] % REST) ) % REST;
        }

        b >>= 1;
    }

    return result;
}

int solution() {
    //fio;

    int n, k;
    scanf("%d %d", &n, &k);

    ll n_factorial = factorials[n];

    ll n_k_factorial = ((factorials[n-k] % REST) * (factorials[k] % REST)) % REST;

    ll n_k_factorial_mod_p = my_pow(n_k_factorial, REST-2);

    

    ll result = ( (n_factorial % REST) * (n_k_factorial_mod_p % REST) ) % REST;

    printf("%lld\n", result);


    return 0;
}

int main() {
    int m;
    cin >> m;

    for(int i = 1; i < 4000001; i++) {
        factorials[i] = ((factorials[i-1] % REST) * (i % REST)) % REST;
    }

    while(m--) {
        solution();
    }
}