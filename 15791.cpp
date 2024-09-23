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

#define REST 1000000007

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

    int n, m;

    cin  >> n >> m;

    ll child = 1;

    for(int i = 1; i <= n; i++) {
        child = ((i % REST) * (child % REST)) % REST;
    }

    ll parent = 1;
    for(int i = 1; i <= m; i++) {
        parent = ((i % REST) * (parent % REST)) % REST;
    }
    for(int i = 1; i <= n-m; i++) {
        parent = ((i % REST) * (parent % REST)) % REST;
    }

    //cout << child << " " << parent << "\n";

    ll parent_result = fastpow(parent, REST-2, REST);

    cout << (   (child % REST) * (parent_result % REST)  ) % REST << "\n";

    return 0;
}
