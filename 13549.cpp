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
int result = -1;
int result_count = 0;

void bfs() { 
    
    while(!q.empty()) {
        auto [num, cnt] = q.front();

        
        cout << "{" << num << ", " << cnt << "}\n";

        q.pop();

        if(num == K) {
            
            result = cnt;
            ++result_count;
        }
        if(result != -1 && result < cnt) {
            break;
        }


        if(visited[num]) {
            continue;
        }

        visited[num] = 1; 

        if(num*2 <= 100000)
            q.push({num*2, cnt+1});
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

    cout << result << "\n";
    cout << result_count << "\n";

    return 0;
}
