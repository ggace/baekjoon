#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(int argc, char* argv[]) {
    fio;

    int l;
    

    cin >> l;

    ll m = 1234567891;
    ll r = 31;

    ll before_r = 1;

    ll result = 0;
    for(int i = 0; i < l; i++) {
        char a;
        cin >> a;
        result += ((a-'a'+1) * before_r) % m;
        result %= m;
        before_r = (before_r * r) % m;
    }

    cout << result << "\n";

    return 0;
}
