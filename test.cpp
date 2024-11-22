#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <deque>
#include <stack>
#include <set>
#include <limits>
#include <sstream>
#include <stdio.h>
#define inn int n; cin>>n;
#define rp(x, y) for(int x = 0; x<y; x++)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp(x, y) make_pair(x, y)
#define ll long long

using namespace std;

int result = __INT_MAX__;
set<int> visited;

void bfs(int current, int end){
    int depth = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(mp(depth, current));
    visited.insert(depth);

    while(!q.empty()){
        int cur = q.top().second;
        int dep = q.top().first;
        q.pop();

        if(cur == end){
            result = min(result, dep);
            return;
        }
        
        if(cur-1 >= 0 && visited.end() == visited.find(cur-1)){
            q.push(mp(dep+1, cur-1));
            visited.insert(cur-1);
        }
        if(cur+1 <= 100000 && visited.end() == visited.find(cur+1)){
            q.push(mp(dep+1, cur+1));
            visited.insert(cur+1);
        }
        if(2*cur <= 100000 && visited.end() == visited.find(2*cur)){
            q.push(mp(dep, 2*cur));
            visited.insert(2*cur);
        }
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin>>N>>K;

    if(N > K){
        cout<<N-K;
        return 0;
    }

    bfs(N, K);
    cout<<result;
    
    return 0;
}