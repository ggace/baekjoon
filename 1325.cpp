#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> v;

void bfs(int n) {
    queue<int> q;
    int visited[10000+1] = {0, };

    q.push(n);

    int count = 0;

    while(!q.empty()) {
        int tmp = q.front();    
        q.pop();
        
        count++;
        for(int i = 0; i < v[tmp].size(); i++) {
            int next = v[tmp][i];
            if(visited[next]){
                continue;
            }
            q.push(next);
        }
    }
}

int main(){
    fio;

    int n, m;

    cin >> n >> m;

    while(m--) {
        int a, b;

        cin >> a >> b;

        v.push_back({b, a});
    }

    return 0;
}
