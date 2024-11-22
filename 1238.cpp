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
    int time;
    Edge(int t, int ti) {
        to = t;
        time = ti;
    }
};

vector<vector<Edge>> edges(10101);
struct Node {
    int current;
    int time;

    Node(int c, int t): current(c), time(t) {}

    bool operator<(const Node& node)const {
        return time > node.time;
    }    
};

bool visited[1010];
vector<int> djik_result(1010);

int djikstra(int start, int end) {
    memset(visited, 0, sizeof(visited));
    fill_n(djik_result.begin(), djik_result.size(), 0);
    priority_queue<Node> pq;
    pq.push(Node(start, 0));

    while(!pq.empty()) {
        auto [cur, time] = pq.top();
        pq.pop();

        if(visited[cur]) {
            continue;
        }
        visited[cur] = true;
        djik_result[cur] = time;

        if(cur == end) {
            return time;
        }

        for(auto [next_node, next_time] : edges[cur]) {
            pq.push(Node(next_node, time+next_time));
        }

    }

    return 0;
}

int n, m, x;

vector<int> result(1010);

int main(int argc, char* argv[]) {
    fio; 

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back(Edge(b, c));
    }

    int final_result = -1;

    for(int i = 1; i <= n; i++) {
        result[i] = djikstra(i, x);
    }
    djikstra(x, 101010);
    for(int i = 1; i <= n; i++) {
        result[i] += djik_result[i];
        final_result = max(final_result, result[i]);
    }

    cout << final_result << "\n";

    

    return 0;
}
