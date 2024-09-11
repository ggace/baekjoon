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

int box[111][111][111];

int main(int argc, char* argv[]) {
    fio;

    int m, n, h;

    cin >> m >> n >> h;

    for(int i = 0; i < h;i ++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[i][j][k];
            }
        }
    }

    

    return 0;
}
