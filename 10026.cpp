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

int normal_sight[111][111];
int rg_sight[111][111];
bool normal_visited[111][111];
bool rg_visited[111][111];

Direction direc[4] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int normal_count = 0;
int rg_count = 0;

void normal_bfs(int i, int j) {
    queue<pii> q;

    q.push({i, j});

    while(!q.empty()) {
        auto [cur_i, cur_j] = q.front();
        q.pop();
        normal_visited[cur_i][cur_j] = true;

        int cur_value = normal_sight[cur_i][cur_j];
        for(auto d : direc) {
            int next_i = cur_i + d.dx;
            int next_j = cur_j + d.dy;

            if(normal_sight[next_i][next_j] == cur_value && !normal_visited[next_i][next_j]) {
                q.push({next_i, next_j});
            }
        }
    }
    ++normal_count;
}

void rg_bfs(int i, int j) {
    queue<pii> q;

    q.push({i, j});

    while(!q.empty()) {
        auto [cur_i, cur_j] = q.front();
        q.pop();
        rg_visited[cur_i][cur_j] = true;

        int cur_value = rg_sight[cur_i][cur_j];
        for(auto d : direc) {
            int next_i = cur_i + d.dx;
            int next_j = cur_j + d.dy;

            if(rg_sight[next_i][next_j] == cur_value && !rg_visited[next_i][next_j]) {
                q.push({next_i, next_j});
            }
        }
    }
    ++rg_count;
}

int main(int argc, char* argv[]) {
    fio; 
    int n;
    cin >> n;

    memset(normal_sight, -1, sizeof(normal_sight));
    memset(rg_sight, -1, sizeof(rg_sight));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if(c == 'R') {
                normal_sight[i][j] = 0;
                rg_sight[i][j] = 0;
            }
            else if(c == 'G') {
                normal_sight[i][j] = 2;
                rg_sight[i][j] = 0;
            }
            else if(c == 'B') {
                normal_sight[i][j] = 1;
                rg_sight[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!normal_visited[i][j]) {
                normal_bfs(i, j);
            }
            if(!rg_visited[i][j]) {
                rg_bfs(i, j);
            }
        }
    }

    cout << normal_count << " " << rg_count<< "\n";
    
    return 0;
}
