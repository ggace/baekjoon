#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio;

    int n, k;

    cin >> n >> k;

    int dp[35][35] = {0};

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= i; j ++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}
