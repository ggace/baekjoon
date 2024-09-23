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

#define REST 1'000'000'007

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
    return result % c;
}

int main(int argc, char* argv[]) {
    fio;

    ll a, b;

    cin >> a >> b;

    if(a == 1) {
        cout << b % REST << "\n";
        return 0;
    }

    ll child = (fastpow(a % REST,b,REST) - 1);
    if(child < 0) {
        child += REST;
    }

    ll parent = fastpow((a-1) % REST, REST-2, REST);

    ll result = ((child % REST) * (parent % REST)) % REST;

    cout << result << "\n";


    return 0;
}
