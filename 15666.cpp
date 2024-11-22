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

vector<int> v;
bool is_having[10101];
int n, m;

void go(int cnt, int max_index, vector<int> seq) {
    if(cnt == m) {
        for(int i = 0; i < seq.size();i++) {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for(int i = max_index; i < v.size(); i++) {
        vector<int> temp = seq;
        temp.push_back(v[i]);
        go(cnt+1, i, temp);
    }
}

int main(int argc, char* argv[]) {
    fio; 
    cin >> n >> m;

    

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(is_having[temp]) {
            continue;
        }
        is_having[temp] = true;
        v.push_back(temp);        
    }

    sort(v.begin(), v.end());

    go(0, 0, {});
    

    return 0;
}