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

struct Edge {
    int to;
    int distance;
};

vector<vector<Edge>> edges(808);
array<int, 2> goal;
vector<int> djik_result(808);
bool visited[808];

struct Node {
    int first;
    int second;
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator<(const Node& node) const {
        return second > node.second;
    }
};

int djikstra(int start, int end) {
    memset(visited, 0, sizeof(visited));
    priority_queue<Node> pq;
    pq.push(Node(start, 0));

    while(!pq.empty()) {
        auto [cur_node, distance] = pq.top();
        pq.pop();

        
        if(visited[cur_node]) {
            continue;
        }
        visited[cur_node] = true;
        djik_result[cur_node] = distance;

        if(cur_node == end) {
            return distance;
        }

        for(auto [next_node, next_distance] : edges[cur_node]) {
            pq.push(Node(next_node, distance + next_distance));
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    fio; 

    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    for(int i = 0; i < 2; i++) {
        cin >> goal[i];
    }
    

    auto one_to_0 = djikstra(1, goal[0]);
    if(one_to_0 == -1) {
        cout << "-1\n";
        return 0;
    }
    auto one_to_1 = djikstra(1, goal[1]);
    if(one_to_1 == -1) {
        cout << "-1\n";
        return 0;
    }

    auto _0_to_1 = djikstra(goal[0], goal[1]);
    if(_0_to_1 == -1) {
        cout << "-1\n";
        return 0;
    }
    auto _1_to_0 = djikstra(goal[1], goal[0]);
    if(_1_to_0 == -1) {
        cout << "-1\n";
        return 0;
    }

    auto _1_to_end = djikstra(goal[1], n);
    if(_1_to_end == -1) {
        cout << "-1\n";
        return 0;
    }
    auto _0_to_end = djikstra(goal[0], n);
    if(_0_to_end == -1) {
        cout << "-1\n";
        return 0;
    }

    cout << min(one_to_0 + _0_to_1 + _1_to_end, one_to_1 + _1_to_0 + _0_to_end) << "\n";


    

    return 0;
}
