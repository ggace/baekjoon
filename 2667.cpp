#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

vector<int> ans;

int arr[25 + 3][25 + 3] = {0};
int vis[25 + 3][25 + 3] = {0};

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};


int bfs(int r, int c) {
    queue<pair<int, int>> q;

    q.push({r, c});

    vis[r][c] = 1;

    int cnt = 1;

    while(!q.empty()) {
        auto [cr, cc] = q.front();

        q.pop(); 

        for(int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(arr[nr][nc] == 0 || vis[nr][nc]) {
                continue;
            }
            vis[nr][nc] = 1;
            q.push({nr, nc});
            cnt++;
        }
    }

    return cnt;
}

int main(){
    //fio;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= n; j++) {
            arr[i][j] = s[j-1] -'0';
        }
    }


    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(vis[i][j] == 1) continue;

            if(arr[i][j] == 1) {
                ans.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << cnt << "\n";

    for(int i = 0; i < cnt; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
