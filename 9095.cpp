#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int dp[12] = {0};

int main(){
    fio;

    int arr[3] = {0,0,0};

    int n; cin>> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 4; j <= k; j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }

        cout << dp[k] << "\n"; 
    }

    return 0;
}
