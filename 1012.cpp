#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int result = 0;
queue<pair<int, int>> q;
int visited[55][55];
int arr[55][55];
int direction[4][2] = {
    {-1,0},
    {1, 0},
    {0, 1},
    {0,-1}
};

void bfs() {
    auto [first_y, first_x] = q.front();
    if(!q.empty() && !visited[first_y][first_x]) {
        result++;
    }
    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        if(visited[y][x]) {
            continue;
        }
        visited[y][x] = 1;

        for(int i = 0; i < 4; i++) {
            int next_y = y + direction[i][0];
            int next_x = x + direction[i][1];
            if(!visited[next_y][next_x] && arr[next_y][next_x]) {
                q.push({next_y, next_x});
            }
        }
        
    }
    
}

void solution() {
    result = 0;
    int m, n, k;

    memset(arr, 0, sizeof(int) * 55 * 55);
    memset(visited, 0, sizeof(int) * 55 * 55);

    cin >> m >> n >> k;

    while(k--) {
        int x, y;
        cin >> x >> y;

        arr[y+1][x+1] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] == 1 && !visited[i][j]) {
                q.push({i, j});
                bfs();
            }
        }
    }

    cout << result << "\n";


}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    while(n--) {
        solution();
    }

    return 0;
}
