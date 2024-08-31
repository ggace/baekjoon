#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[1000+1] = {1, 1, };

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] % 10007 + dp[i-2]*2 % 10007) % 10007;
    }

    cout << dp[n] << "\n";

    return 0;
}
