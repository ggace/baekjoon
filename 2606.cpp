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

void graph_init() {
    graph.clear();
    fill_n(dfs_visited, graph_size, 0);
    fill_n(bfs_visited, graph_size, 0);
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

int result = 0;

template <typename T>
void bfs(T node) {

    bfs_visited[node] = true;

    queue<T> q;
    q.push(node);

    while(!q.empty()) {
        node = q.front();
        q.pop();

        result ++;
        for(auto g : graph[node]) {
            if(!bfs_visited[g]) {
                q.push(g);
                bfs_visited[g] = true;
            }
        }
    }

}


int main(int argc, char* argv[]) {
    
    int computer_count, computer_pair;

    cin >> computer_count >> computer_pair;

    for(int i = 0; i < computer_pair; i++) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

  //  graph_init();

    bfs<int>(1);

    cout << result-1 << "\n";


    return 0;
}