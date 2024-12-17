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

struct Edge{
    ll to;
    ll distance;
    ll time;
};

struct Node {
    int node;
    ll going_time;
    ll fish;

    Node(int n, ll g, ll f): node(n), going_time(g), fish(f) {}

    bool operator<(const Node& node)const {
        return fish < node.fish;
	}
};

int n, m;
vector<vector<Edge>> edges(101010);
// bool visited[101010];
vector<ll> visited(101010, 0);

void dijkstra(ll start) {
    priority_queue<Node> pq; // node, time, fish

    pq.push(Node(start, 0, LONG_LONG_MAX));
    visited[start] = LONG_LONG_MAX;

    while(!pq.empty()) {
        auto [cur, time, fish] = pq.top();
        pq.pop();
        // debug_value(cur);
        // debug_value(fish);
        // debug("\n");

        if(visited[cur] > fish) {
            continue;
        }

        if(cur == n) {
            cout << fish << "\n";
            exit(0);
        }

        for(auto [next, next_distance, dis_time]: edges[cur]) {
            if(dis_time - time - next_distance >= 0 && visited[next] < min(fish, dis_time - time - next_distance)) {
                pq.push(Node(next, time+next_distance, min(fish, dis_time - time - next_distance) ));
                visited[next] = min(fish, dis_time - time - next_distance);
            }
            
        }
    }
    cout << "-1\n";
}

int main() {

    fio;

    cin >> n >> m;
    while(m--) {
        int u, v, d, t;
        cin >> u >> v >> d >> t;
        edges[u].push_back({v, d, t});
        edges[v].push_back({u, d, t});
    }

    dijkstra(1);
    
    return 0;
}
