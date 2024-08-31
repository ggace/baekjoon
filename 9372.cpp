#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

void solution() {
    int n, m;
    cin >> n >> m;


    vector<pair<int, int>> v;

    for(int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        v.push_back({a, b});
    }


    cout << n-1 << "\n";

}

int main(){
    fio;

    int t;

    cin >> t;

    while(t--) {
        solution();
    }

    return 0;
}
