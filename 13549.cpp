#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <queue>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int n, K;

queue<pair<int, int>> q;
int visited[101010 * 8] = {0, };

void bfs() { 
    
    while(!q.empty()) {
        auto [num, cnt] = q.front();

        //cout << "{" << num << ", " << cnt << "}\n";

        q.pop();

        if(num == K) {
            cout << cnt << "\n";
            break;
        }

        if(visited[num]) {
            continue;
        }

        visited[num] = 1; 

        if(num*2 <= 100000)
            q.push({num*2, cnt});
        if(num-1 >= 0)
            q.push({num-1, cnt+1});
        if(num+1 <= 100000)
            q.push({num+1, cnt+1});
        
    }
}

int main(){
    fio;

    cin >> n >> K;
    q.push({n, 0});

    bfs();

    return 0;
}
