#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[250] = {0, 1, 3};

void solution(int n) {
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    cout << dp[n] << "\n";
}

int main(){
    //fio;
    

    int n;
    while(cin >> n) {
        solution(n);
    }

    return 0;
}
