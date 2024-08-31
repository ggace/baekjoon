//처음 풀이
/*#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    vector<int> v;

    int n;

    cin >> n;

    v.push_back(n); 
    v.push_back(0); 

    int x;
    
    int count = 0;

    for(int i = 0; true; i++){
        if(v[i] == 0){
            count++;
            v.push_back(0);
            continue;
        }
        if(v[i] == 1){
            x = i;
            break;
        }
        if(!(v[i] % 3)) {
            v.push_back(v[i] / 3);
        }
        if(!(v[i] % 2))
            v.push_back(v[i] / 2);
        if(v[i] != 0)
            v.push_back(v[i] - 1);
        
    }

    cout << count << "\n";

    return 0;
}*/

//dp
/*
#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int dp[1000001] = {0};

int main(){
    fio();
    
    int n;

    cin >> n;

    for(int i = 0; i < 1000001; i++) {
        dp[i] = 0x7fffffff;
    }

    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] +1);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] +1);
        dp[i] = min(dp[i], dp[i-1] +1);
    }

    cout << dp[n] << "\n";

    return 0;
}
*/

//bfs

#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <queue>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int vis[1000000+1] = {0};

int main(){
    fio;

    int n; cin>> n;

    queue<pair<int, int>> q;

    q.push({1,0});

    while(!q.empty()) {
        auto [cur, cnt] = q.front();

        q.pop();        
        if(cur == n) {
            cout << cnt << "\n";

            break;
        }

        if(cur * 3 < 1000001 && vis[cur* 3] == 0) {
            q.push({cur * 3, cnt + 1});
            vis[cur*3] = 1;
        }
        if(cur * 2 < 1000001 && vis[cur * 2] == 0) {
            q.push({cur * 2, cnt + 1});
            vis[cur * 2] = 1;
        }
        if(cur + 1 < 1000001 && vis[cur + 1] == 0) {
            q.push({cur + 1, cnt + 1});
            vis[cur + 1] = 1;
        }
    }

    return 0;
}
