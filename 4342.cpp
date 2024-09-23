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

ll my_gcd(ll a, ll b, ll cnt) {
    cout << a << ", " << b << " : " << cnt << "\n";
    if(b == 0) {
        return cnt;
    }
    return my_gcd(b, a%b, cnt+1);
}

int main(int argc, char* argv[]) {
    

    while(true) {
        int a, b;
        cin >> a >> b;
        if(!(a | b)) {
            break;
        }
        ll result = my_gcd(max(a, b), min(a, b), 0);
        if(result & 1) {
            cout << "A wins\n";
        }
        else {
            cout << "B wins\n";
        }
    }

    return 0;
}
