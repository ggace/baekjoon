#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 < i2;
}

vector<pair<int, string>> v;

int main(int argc, char* argv[]) {
    fio;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;

        v.push_back({a, s});
        
    }

    stable_sort(v.begin(), v.end(), [](pair<int, string> p1, pair<int, string> p2){
        return p1.first < p2.first;
    });

    for(int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }



    return 0;
}
