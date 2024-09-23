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

vector<int> sq;

int n, o1, o2, sq_count;

ll go(int i, int result) {
    if(i == sq.size()) {
        return result;
    }
    int c_sq = sq[i];
    int d1 = abs(o1 - c_sq);
    int d2 = abs(o2 - c_sq);
    //cout << i << " : " << o1 << " " << o2 << " -> " << c_sq << " - " << result <<  "\n";
    if(d1 == 0 || d2 == 0) {
        
        return go(i+1, result);
    }

    if(d1 == d2) {        
        int temp_o1 = o1;
        o1 = c_sq;
        int w1 = go(i+1, result + d1);


        o1 = temp_o1;
        int temp_o2 = o2;
        o2 = c_sq;
        int w2 = go(i+1, result + d2);
        o2 = temp_o2;

        return min(w1, w2);
    }
    if(d1 > d2) {
        
        o2 = c_sq;
        return go(i+1, result + d2);
    }
    if(d1 < d2) {
        
        o1 = c_sq;
        return go(i+1, result + d1);
    }

    return 0;
}

int main(int argc, char* argv[]) {
    fio;

    cin >> n >> o1 >> o2 >> sq_count;

    for(int i = 0; i < sq_count; i++) {
        int a; 
        cin >> a;

        sq.push_back(a);
    }

    cout << go(0, 0);
    

    return 0;
}
