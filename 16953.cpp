typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()

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
bool is_prime[500+1] = {1,1,0}; // 0이 소수
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

void bfs(int a, int b) {
    
    queue<pll> q;
    q.push({a, 1});

    while(!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        if(cur == b) {

            cout << cnt << "\n";
            return;
        }
        if(cur * 2 <= 1e9 && cur*2 <= b)
            q.push({cur * 2, cnt+1});
        if(cur *10 + 1 <= 1e9 && cur * 10 + 1 <= b) {
            q.push({cur * 10 + 1, cnt + 1});
        }
    }

    cout << "-1\n";
}

int main(int argc, char* argv[]) {
    fio;

    int a, b;

    cin >> a >> b;

    bfs(a, b);

    

    return 0;
}
