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

bool prime[500] = {1,1,0};
vector<int> ps;

void siv(int n) {

    for(int i = 2; i <= n; i++)  {
        if(!prime[i]) ps.push_back(i);
        for(auto p : ps) {
            if(i * p > n) break;
            prime[i*p] = 1;
            if(!(i % p)) continue;
        }
    }
}

ll result = 1;

bool is_prime(int n)  {
    for(ll i = 2; i * i <= n; i++) {
        if(!(n % i)) {
            return false;
        }
    }

    return true;
}

void is_flt(ll n) {
    bool is_true = true;
    for(auto a : ps) {
        if(fastpow(a, n-1, n) != 1) {
            return;
        }
    }
    
    if(!is_prime(n)) {
        cout << n << "\n";
        exit(0);
    }
    
}

int main(int argc, char* argv[]) {
    //fio;

    siv(500);

    for(ll i = 2; log10(i) < 15; i++) {
        is_flt(i);
        cout << i << "\n";
    }

    cout << result << "\n";

    return 0;
}
