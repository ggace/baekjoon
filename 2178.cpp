#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int graph[111][111];
int visited[111][111];
queue<pair<pair<int, int>, int>> q;
int direction[4][2] = {
    {-1,0},
    {1, 0},
    {0, 1},
    {0,-1}
};

int main(int argc, char* argv[]) {
    //fio;

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char t;
            cin >> t;

            graph[i][j] = t - '0';
        }
    }

    

    q.push({{1,1}, 1});
    visited[1][1] = 1;

    while(!q.empty()) {
        auto [pos, count] = q.front();
        auto [y, x] = pos;
        
        q.pop();
        

        if(y == n && x == m) {
            cout << count << "\n";
            break;
        }

        for(int i = 0; i < 4; i++) {
            int next_i = y + direction[i][0];
            int next_j = x + direction[i][1];

            if(graph[next_i][next_j] && !visited[next_i][next_j]) {
                visited[next_i][next_j] = 1;
                q.push({{next_i, next_j}, count+1});
            }
        }

        
    }

    return 0;
}
