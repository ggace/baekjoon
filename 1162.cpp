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

struct Edge {
    int to;
    ll time;
};

int n, m, k;
vector<vector<Edge>> edges;
ull result[10101][22];
bool visited[10101][22];

struct Node {
    int index;
    ull time;
    int cover_remain;

    Node(int i, ll t, int c) : index(i), time(t), cover_remain(c){}

    bool operator<(const Node& node)const {

		return time > node.time;
	}
};

void dijkstra(int start, int goal) {

    priority_queue<Node> pq;
    pq.push(Node(start, 0, k));

    while(!pq.empty()) {
        auto [cur, time, cover_remain] = pq.top();
        pq.pop();

        if(visited[cur][cover_remain]) {
            continue;
        }
        visited[cur][cover_remain] = true;
        
        if(cur == goal) {
            continue;
        }

        for(auto [next_node, next_time]: edges[cur]) {
            if(time + next_time < result[next_node][cover_remain]) {
                pq.push(Node(next_node, time + next_time, cover_remain));
                result[next_node][cover_remain] = min(result[next_node][cover_remain], time+next_time);
            }

            if(time < result[next_node][cover_remain-1] && cover_remain) {
                pq.push(Node(next_node, time, cover_remain-1));
                result[next_node][cover_remain-1] = min(result[next_node][cover_remain-1], time);
            }
        }
    }

    ull r = -1;
    for(int i = 0; i <= k; i++) {
        r = min(r, result[goal][i]);
    }

    cout << r << "\n";

    
}

int main(int argc, char* argv[]) {
    fio; 


    cin >> n >> m >> k;
    edges.resize(m+1);
    memset(result, -1, sizeof(result));

    for(int i = 0; i < m; i++) {
        int a, b;
        ll t;
        cin >> a>> b >> t;
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }
    dijkstra(1, n);

    return 0;
}
