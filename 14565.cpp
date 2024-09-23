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

char visited[1'000'000'000'000 / 8];

int main(int argc, char* argv[]) {
    fio;

    ll n, a;

    cin >> n >> a;

    cout << n-a << " ";

    for(ll c = 0; c < n; c++) {
        if ((a * (c%n)) % n == 1) {
            cout << c << "\n";
            break;
        }
        
    }

    return 0;
}
