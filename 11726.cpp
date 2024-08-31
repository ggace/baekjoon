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
    int dp[1000+1];

    dp[1] = 1;
    dp[2] = 2;

    cin >> n;

    for(int i = 3; i <=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout << dp[n] << "\n";

    return 0;
}
