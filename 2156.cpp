#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<array<int, 3>> v = {{-1,-1,-1}};

int main(){
    fio;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;

        cin >> a;

        array<int, 3> t;

        if(max(v[i][0], max(v[i][1], v[i][2])) == -1) {
            t[0] = 0;
            t[1] = a;
            t[2] = -1;

            v.push_back(t);
            continue;

        }

        t[0] = max(v[i][0], max(v[i][1], v[i][2]));
        t[1] = v[i][0] + a;
        t[2] = v[i][1] + a;

        v.push_back(t); 

        //cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    }

    cout << max(v[n][0], max(v[n][1], v[n][2])) << "\n";

    return 0;
}
