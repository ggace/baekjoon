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

int dp[111][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1}
};

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1] % 1000000000;
        for(int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8] % 1000000000;
    }

    int result = 0;

    for(int i = 0; i < 10; i++) {
        result += dp[n][i];
        result %= 1000000000;
    }

    cout << result << "\n";

    
    return 0;
}