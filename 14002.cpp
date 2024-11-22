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

vector<int> v(1010);
vector<int> dp(1010);
vector<vector<int>> route(1010);

int main(int argc, char* argv[]) {
    fio; 

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        dp[i] = 1;
        route[i] = {i};
    }

    for(int i = 0; i < n; i++) {
        int maximum = 1;
        int index = -1;
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j] && maximum < dp[j] + 1) {
                maximum = dp[j] + 1;
                index = j;
            }
            
        }
        dp[i] = maximum;
        if(index != -1) {
            route[i] = route[index];
            route[i].push_back(i);
        }
/*
        cout << i << ": ";
        cout << index << " >> \n";
        for(int j = 0; j < route[i].size(); j++) {
            cout << route[i][j] << " ";
        }
        cout << "\n\n";
*/
    }

    int result = -1;
    int final_index = -1;
    for(int i = 0; i < n; i++) {
        if(result < dp[i]) {
            final_index = i;
            result = dp[i];
        }
    }
    cout << result << "\n";
    for(int i = 0; i < route[final_index].size(); i++) {
        cout << v[route[final_index][i]] << " ";
    }
    cout << "\n";

    return 0;
}
