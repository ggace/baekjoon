#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <queue>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int result = 0;

int mp[1000 + 2][1000 + 2];
int visited[1000 + 2][1000 + 2];

queue<pair<pair<int, int>, int>> q;

int n, m;

int direction[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};


void bfs() {
    while(!q.empty()) {

        auto [pos, cnt] = q.front();

        q.pop();

        if(visited[pos.first][pos.second]) {
            
            continue;
        }

        visited[pos.first][pos.second] = 1;
        mp[pos.first][pos.second] = cnt;
        
        result = cnt;
/*
        cout << cnt << "\n";    
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++){
                cout << mp[i][j] << " ";
            }

            cout << "\n";
        }

        cout << "\n";
        */
        for(int i = 0; i < 4; i++) {
            
            int nr = pos.first + direction[i][0];
            int nc = pos.second + direction[i][1];

            if(nr > m || nr < 1 || nc > n || nc < 1) continue;

            
            if(mp[nr][nc] != 0){
                q.push({{nr, nc}, cnt+1});
            }
            
            
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j] == 0) {
                mp[i][j] = -1;
            }
        }
    }

    
}

int main(){
    //fio;

    

    cin >>m >> n;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 0) {
                visited[i][j] = -1;
            }
            if(mp[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }
    bfs();

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
