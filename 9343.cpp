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

#define REST 1000000007

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

void solution() {
    int n;

    cin >> n;

    ll N = 2*n;

    cout << N << " " << R << "\n";

    ll child = 1;
    for(ll i = 1; i <= N; i++) {
        child = ( (child % REST) * (i % REST) ) % REST;
    }

    ll parent = 1;
    for(ll i = 1; i <= R; i++) {
        parent = ((parent % REST) * (i % REST)) % REST;
    }
    for(ll i = 1; i <= N-R; i++) {
        parent = ((parent % REST) * (i % REST)) % REST;
    }


    cout << child << " " << parent << "\n";
    ll parent_result = fastpow(parent, REST-2, REST);

    cout << ( (parent_result % REST) * (child % REST) ) % REST << "\n\n";
}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    while(n--) {
        solution();
    }

    return 0;
}
