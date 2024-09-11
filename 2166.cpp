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

vector<pll> v;

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({x,y});
    }
    v.push_back(v[0]);

    ll result1 = 0;
    ll result2 = 0;
    

    for(int i = 0; i < n; i++) {
        result1 += v[i].first * v[i+1].second;
        result2 += v[i+1].first * v[i].second;
    }

    printf("%.1f\n", abs(result1-result2) / 2.);



    return 0;
}
