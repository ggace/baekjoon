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

bool is_prime(ll p) {
    for(ll i = 2; i * i <= p; i++) {
        if(p % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    fio;

    while(true) {
        ll p, a;

        cin >> p >> a;

        if(p == 0 && a == 0) {
            break;
        }

        ll result = fastpow(a, p-1, p);

        if(result == a && !is_prime(p)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
