#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<vector<int>> v(10001);
vector<int> djik_result;
int max_count = -1;
bool visited[10000+1];

void bfs(int n) {
    
}

int main(){
    fio;

    int n, m;

    cin >> n >> m;

    while(m--) {
        int a, b;

        cin >> a >> b;

        v[b].push_back(a);
    }

    

    return 0;
}
