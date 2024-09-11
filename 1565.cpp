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

#define REST 1000000007

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

vector<pll> v;

int result = 0;

int main(int argc, char* argv[]) {
    fio;

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;

        result += (b%REST * fastpow(a, REST-2, REST)) % REST;
        result %= REST;
    }

    cout << result << "\n";

    return 0;
}
