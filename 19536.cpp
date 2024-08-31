#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, bool>> v; // true: potato, false: rock

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

bool compare(int n, pair<int, int> const& p) {
    return p.first < n;
}

void solution() {
    int x;
    cin >> x;

    auto next_index = upper_bound(v.begin(), v.end(), 0, compare);
}

int main(){
    fio;

    int n, q;

    string s;

    cin >> n >> q;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'P' ) {
            v.push_back({i, true});
        }
        else if(s[i] == 'R') {
            v.push_back({i, false});
        }
    }

    while(q--) {
        solution();
    }

    return 0;
}
