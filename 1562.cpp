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

    int n;

    cin >> n;

    ll dp[101][11];

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    dp[1][10] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        cout << dp[i][0] << " ";
        for(int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i-1][j-1] % 1000000000 + dp[i-1][j+1] % 1000000000) % 1000000000;

            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    int result = 0;
    for(int i = 0; i <= 9; i++) {
        result += dp[n][i] % 1000000000;
    }

    cout << result << "\n";
    

    return 0;
}
