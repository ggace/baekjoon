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

vector<int> A;

int main(int argc, char* argv[]) {
    fio;

    int n, l, r;

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            cout << r - l + 1 << "\n";
            return 0;
        }
        A.push_back(a);
    }



    return 0;
}
