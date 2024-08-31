#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

char dp[10000000] = {0,1,2,};

int main(){
    fio;

    int n;

    cin >> n;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];

        dp[i] %= 10;
    }

    cout << (int)dp[n] << "\n";
    


    return 0;
}
