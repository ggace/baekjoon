#define fio { \
    cin.tie(0); \
    cout.tie(0); \
    ios_base::sync_with_stdio(false); \
};
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, i) for(i = a; i < b; i++) 
#define foreach(l, ele) for(ele : l)
#define println(s) cout << s << "\n"

#include <bits/stdc++.h>

using namespace std;



ll fastpow(ll a, ll n, ll c){
    ll result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=c) result%=c;
        }
        a*=a;
        if(a>=c) a%=c;
        n>>=1;
    }
    return result;
}

array<vector<int>, 50505> graph;
array<int, 50505> parent;
array<int, 50505> depth;
bool visited[50505];

void find_depth(const int& n) {
    queue<pair<int, int>> q;
    q.push({n,0});
    visited[n] = true;

    while((!q.empty())) {
        auto [current, current_depth] = q.front();
        q.pop();
        
        depth[current] = current_depth;

        for(auto next : graph[current]) {
            if(visited[next]) continue;
            parent[next] = current;
            visited[next] = true;
            
            q.push({next, current_depth+1});
        }
    }
}

int match_depth(int index, const int& from_depth, const int& to_depth) {
    for(int i = 0; i < from_depth - to_depth; i++) {
        index = parent[index];
    }
    return index;
}

int main(int argc, char* argv[]) {
    //fio;
    
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    find_depth(1);

    int m;

    cin >> m;

    while(m--) {
        int a, b;

        cin >> a >> b;

        int depth_a = depth[a];
        int depth_b = depth[b];
        //cout << a << " " << b << ": " << depth[a] << " " << depth[b] << "\n";

        if(depth_a > depth_b) {
            //cout << "a\n";
            a = match_depth(a, depth_a, depth_b);
        }
        else if (depth_a < depth_b) {
            //cout << "b\n";
            b = match_depth(b, depth_b, depth_a);
        }

        //cout << a << " " << b << ": " << depth[a] << " " << depth[b] << "\n\n";

        if(a == b) {
            cout << a << "\n";
            continue;
        }

        while(true) {
            a = parent[a];
            b = parent[b];
            if(a == b) {
                cout << a << "\n";
                break;
            }
        }
        
    }



    return 0;
}
