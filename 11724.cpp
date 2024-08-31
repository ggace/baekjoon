#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<vector<int>> line(1001);

bool visited[1000];

queue<int> q;

void bfs() {
    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(auto next : line[current]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;

        cin >> u >> v;

        line[u].push_back(v);
        line[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            q.push(i);
            bfs();
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
