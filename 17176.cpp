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

int arr[53];

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;

        cin >> a;

        arr[a] += 1;
    }

    char s[100000];

    scanf("%[^\n]s", s);
    

    for(int i = 0; i < n; i++) {
        char c = s[i];
        int index;
        if(c == ' ') {
            index = 0;
        }
        else if('A' <= c && c <= 'Z') {
            index = c - 'A' + 1;
        }
        else if('a' <= c && c <= 'z') {
            index = c - 'a' + 27;
        }

        if(!arr[index]) {
            cout << "n\n";
            return 0;
        }
        else {
            arr[index]--;
        }
    }

    cout << "y\n";

    return 0;
}
