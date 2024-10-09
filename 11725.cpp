#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, i) for(i = a; i < b; i++) 
#define foreach(l, ele) for(ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

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

vector<vector<int>> v(101010);
bool visited[101010];
vector<int> parent_node_list(101010);

void bfs(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        int current_node = q.front();
        q.pop();
        for(int next_node : v[current_node]) {
            if(visited[next_node]) {
                continue;
            }
            visited[next_node] = true;
            q.push(next_node);
            parent_node_list[next_node] = current_node;
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b;cin >>a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);

    for(int i = 2; i <= n; i++) {
        cout << parent_node_list[i] << "\n";
    }

    return 0;
}
