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

    ll dp[1001][11] = {
        {1,1,1,1,1,1,1,1,1,1}
    };

    for(int i = 1; i < n; i++) {
        
        dp[i][0] = 1;
        for(int j = 1; j< 10; j++) {
            dp[i][j] = (dp[i][j-1] % 10007 + dp[i-1][j] % 10007) % 10007;
        }
    }

    ll sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += dp[n-1][i];
        sum %= 10007;
    }

    cout << sum << "\n";

    return 0;
}
