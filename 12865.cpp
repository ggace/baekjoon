#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vec;

int dp[101][101010];

int main() {
    fio;

    int n, k;

    cin >> n >> k;
    vec.push_back({0,0});
    for(int i = 1; i <= n; i++) {
        int a, b;

        cin >> a >> b;

        vec.push_back({a, b});

        dp[i][a] = b;
    }

    for(int j = 0; j <= k; j++) {
        
        dp[0][j] = 0;
        
    }

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        auto [w, v] = vec[i];
        for(int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j-1], max(dp[i-1][j], dp[i][j]));
            if(j - w >= 0)
                dp[i][j] = max(dp[i-1][j-w] + v, dp[i][j]);
            
        }
        
    }

    cout << dp[n][k] << "\n";





    return 0;
}