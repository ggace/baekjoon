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

#define REST 998'244'353

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

int main(int argc, char* argv[]) {
    fio;

    ll N, M;

    cin >> N >> M;

    int n = N-M;

    ll t = fastpow(25, n, REST);
    

    ll result = (((t * t) % REST) * fastpow(n+1, 2, REST)) % REST;

    cout << result << "\n";

    for(ll i = 1; i <= n; i++) {
        ll temp = fastpow(25, n-i, REST);
        result = (result + ((((t % REST)*(temp%REST)) % REST) * ((((n-i+1) % REST * (n+1) % REST) % REST) * 2) % REST) % REST ) % REST;
    }

    cout <<result << "\n";

    return 0;
}
