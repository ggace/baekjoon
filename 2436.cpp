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

ll g, l;

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

ll gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

void solution(ll r) {
    for(ll i = sqrt(r); i >= 1; i--) {
        if(!(r%i)) {
            
            if(gcd(i, r/i) == 1) {
                cout << i *g << " " << r/i*g << "\n";
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    cin >> g >> l;

    ll r = l/g;

    solution(r);

    





    return 0;
}
