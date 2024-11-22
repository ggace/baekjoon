#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()
#define arri(n) array<int, n>
#define arrl(n) array<ll, n>

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

struct Compare {
	bool operator() (const arri(3) &a, const arri(3) &b) const{
        if(!a[0]) {
            return !(0<1);
        }
        if(!b[0]) {
            return !(1<0);
        }
        if(!a[1]) {
            return !(1<0);
        }
        if(!b[1]) {
            return !(0<1);
        }
        
        int a_open_minus_close = a[1] - a[0];
        int b_open_minus_close = b[1] - b[0];
        if(a_open_minus_close < 0 && b_open_minus_close < 0) {
            if(a[1] == b[1]) {
                return !(a[0] < b[0]);
            }
            return !(a[1] > b[1]);
        }
        if(b_open_minus_close < 0) {
            return !(0<1);
        }
        if(a_open_minus_close < 0) {
            return !(1<0);
        }
        if(a_open_minus_close == 0 && b_open_minus_close == 0) {
            return !(a[0] < b[0]);
        }
        if(a_open_minus_close == 0) {
            return !(1<0);
        }
        if(b_open_minus_close == 0) {
            return !(0<1);
        }
        if(a[0] == b[0]) {
            return !(a[1] > b[1]);
        }
        return !(a[0] < b[0]);
		
	}
};

priority_queue<arri(3), vector<arri(3)>, Compare> close_open_index;
vector<int> djik_result;

int main(int argc, char* argv[]) {
    fio;

    int n;cin >> n;

    loop(0,n,int, i) {
        string s;
        cin >> s;

        int close = 0;
        int open = 0;
        for(auto c : s) {
            if(c == '(') ++open;
            else {
                if(open > 0) --open;
                else ++close;
            }
        }

        close_open_index.push({close, open, i+1});
    }

    ll final_open = 0;

    while(!close_open_index.empty()) {
        arri(3) current_arr = close_open_index.top();
        close_open_index.pop();

        final_open -= current_arr[0];
        if(final_open < 0) {
            goto IMPOSSIBLE;   
        }
        final_open += current_arr[1];
        djik_result.push_back(current_arr[2]);
    }
    if(final_open != 0){
        goto IMPOSSIBLE;
    }

    for(auto r : djik_result) {
        cout << r << "\n";
    }

    return 0;
IMPOSSIBLE:
    cout << "impossible\n"; 
    return 0;
}
