typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()
#define PRIME_SIZE 5
#define PIE M_PIf64
#define arri(n) array<int, n>
#define arrl(n) array<ll, n>
#define input(type, value) type value; cin >> value;

#ifdef BOJ
#define debug(x)  ((void)0);
#define debug_value(x)  ((void)0);
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#else
#define debug(x)  cout << "[Debug] " << x;
#define debug_value(x)  cout << "[Debug] " << #x << " is " << x << '\n';
#define fio ((void)0);
#endif

#include <bits/stdc++.h>

using namespace std;

class Direction {
    public:
        int dx;
        int dy;
};

class Position {
    public:
        int x;
        int y;
};

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

vector<ll> prime_list;
bool is_prime[PRIME_SIZE+1] = {1,1,0}; // 0이 소수
void siv(ll n) {
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) prime_list.push_back(i);
        for(auto p : prime_list) {
            if(i*p > n) break;
            is_prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}

priority_queue<int> low;
priority_queue<int, vector<int>, greater<int>> high;

int main(int argc, char* argv[]) {
    fio; 

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(high.empty()) {
            low.push(a);
        }
        else if(high.top() < a) {
            high.push(a);
        }
        else {
            low.push(a);
        }

        while(low.size() > ceil(i/2.)){
            high.push(low.top());
            low.pop();
        }
        while(high.size() > i/2) {
            low.push(high.top());
            high.pop();
        }
        //cout << i << " - low  size: " << low.size() << "\n";
        //cout << i << " - high size: " << high.size() << "\n";

        cout << low.top() << "\n";
    }

        

    return 0;
}
