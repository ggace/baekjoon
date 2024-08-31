#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<vector<int>> v(100001);
bool visited[100001];


template <typename T>
void dfs(T node) {
    stack<T> s;
    cout << node;
    visited[node] = true;

    

}


int main(int argc, char* argv[]) {
    fio;

    int n, m, r;

    cin >> n >> m >> r;

    while(m--) {
        int a,b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);        
    }

    dfs<int>(r);



    return 0;
}