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

vector<pll> sn;
vector<ll> an;
ll n, a;

vector<pair<__int128_t, __int128_t>> djik_result;

ll my_gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }

    //cout << a << " " << b << "\n";
    sn.push_back({b, a%b});
    an.push_back(a / b);

    return my_gcd(b, a%b);
}



int main(int argc, char* argv[]) {
    fio;

    cin >> n >> a;

    cout << n-a << " ";

    if(a == 1) {
        cout << "1\n";
        return 0;
    }

    sn.push_back({n, a});

    ll t = my_gcd(n, a);

    if(t != 1) {
        cout << "-1\n";
        return 0;
    }
    sn.pop_back();
    sn.pop_back();
    an.pop_back();

    ll j = 0;
    
    djik_result.push_back({1, -an[an.size()-1]});
    for(ll i = an.size()-2; i >= 0 ; i--) {
        pair<__int128_t, __int128_t> before = djik_result[j++];
        djik_result.push_back({before.second % n, ((before.first % n) - ((before.second % n) * ((__int128_t)an[i] % n)) % n ) %n});
    }

    ll final_result = djik_result.back().second % n;

    if(final_result < 0) {
        final_result += n;
    }
    
    cout << final_result << "\n";
    return 0;
}
