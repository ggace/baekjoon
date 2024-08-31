#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

#define graph_size 1000
vector<vector<int>> graph(graph_size+1);
bool dfs_visited[graph_size+1];
bool bfs_visited[graph_size+1];

void init() {
    graph.clear();
    fill_n(dfs_visited, graph_size+1, 0);
    fill_n(bfs_visited, graph_size+1, 0);
}

template <typename T>
void dfs(T node) {

    dfs_visited[node] = true;

    cout << node << " ";

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

    cout << node << " ";

    while(!q.empty()) {
        node = q.front();
        
        q.pop();
        for(auto g : graph[node]) {
            if(!bfs_visited[g]) {
                q.push(g);
                cout << g << " ";
                bfs_visited[g] = true;
            }
        }
    }

}

int main(){
    //fio;

    int n, m, v;
    
    cin >> n >> m >> v;

    while(m--) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < graph_size+1;i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs<int>(v);
    cout << "\n";
    bfs<int>(v);
    cout << "\n";

    return 0;
}