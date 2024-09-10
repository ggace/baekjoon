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

vector<pii> v;
int result = 0;

bool compare(pii a, pii b) {
    if(a.first == b.first) {
        a.second < b.second;
    }

    return a.first < b.first;
}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a == b) {
            ++result;
        }
        v.push_back({a, b});        
    }

    sort(v.begin(), v.end(), compare);

    

    return 0;
}
