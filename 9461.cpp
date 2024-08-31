#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

#define graph_size 1000
vector<vector<int>> graph(graph_size+1);
bool dfs_visited[graph_size+1];
bool bfs_visited[graph_size+1];

void graph_init() {
    graph.clear();
    fill_n(dfs_visited, graph_size+1, 0);
    fill_n(bfs_visited, graph_size+1, 0);
}

template <typename T>
void dfs(T node) {

    dfs_visited[node] = true;

    for(auto g : graph[node]) {
        if(!dfs_visited[g]) {
            
            dfs<T>(g);
        }
    }

}

template <typename T>
void bfs(T node) {

    bfs_visited[node] = true;

    queue<T> q;
    q.push(node);

    while(!q.empty()) {
        node = q.front();
        
        q.pop();
        for(auto g : graph[node]) {
            if(!bfs_visited[g]) {
                q.push(g);
                bfs_visited[g] = true;
            }
        }
    }

}

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

ll dp[111] = {0,1,1,1,2,2};

void solution() {
    int n;

    cin >> n;

    for(int i = 5; i <= n; i++) {
        if(dp[i]) {
            continue;
        }
        dp[i] = dp[i-5] + dp[i-1];
    }

    cout << dp[n] << "\n";
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