//#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

#ifdef BOJ
#define debug(x)  ((void)0);
#define debug_value(x)  ((void)0);
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#else
#define debug(x)  cout << "[Debug] " << x;
#define debug_value(x)  cout << "[Debug] " << #x << " is " << x << '\n';
#define fio cout << "fastio\n";
#endif

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
bool is_prime[2+1] = {1,1,0}; // 0이 소수
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

int n, k;
int w;


void solution() {
    vector<int> times(1001);
    vector<vector<int>> childs(1001);
    vector<int> root;
    vector<int> possible_parent_count(1001);
    vector<int> result(1001);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> times[i];
        
    }
    
    
    loop(0, k, int, i) {
        int x, y;
        cin >> x >> y;
        childs[x].push_back(y);
        ++possible_parent_count[y];
        
    }

    int goal; cin >> goal;

    for(int i = 1; i <= n; i++) {
        if(possible_parent_count[i] == 0) {
            root.push_back(i);
        }
    }

    queue<pii> q;
    for(auto r : root) {
        q.push({r, times[r]});
    }

    while(!q.empty()) {
        auto [current_node, current_time] = q.front();
        q.pop();
        
        if(current_node == goal) {
            cout << current_time << "\n";
            break;
        }

        for(auto c : childs[current_node]) {
            
            int temp_time = times[c] + current_time;
            result[c] = max(result[c], temp_time);
            
            --possible_parent_count[c];
            if(possible_parent_count[c] == 0) {
                q.push({c, result[c]});
            }
        }
    }


}

int main(int argc, char* argv[]) {
    fio;
    int t;
    cin >> t;
    while(t--) {
        solution();
    }
    return 0;
}
