#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<array<int, 3>> v = {};

int main(){
    fio;

    int n;

    cin >> n;

    v.push_back({0,0,0});

    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        r += min(v[i][1], v[i][2]);
        g += min(v[i][0], v[i][2]);
        b += min(v[i][0], v[i][1]);

        v.push_back({r,g,b});

        //cout << r << " " << g << " " << b << "\n";
    }

    cout << min(min(v[n][0], v[n][1]), v[n][2]) << "\n";







    return 0;
}
