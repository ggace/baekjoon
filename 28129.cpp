#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[3001][3010];

int main(){
//    fio;

    

    int n, k;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        if(i == 1) {
            cout << "executed\n";
            for(int j = a; j <= b; j++) {
                cout << j << " ";
                dp[1][j] = 1;
            }
            cout << "\n";
            continue;
        }

        for(int j = a; j <= b; j++) {
            cout << j << " ";
            if(j < k) {
                
            }
            dp[i][j] = dp[i-1][j-3] + dp[i-1][j-3] + dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j+2] + dp[i-1][j+3];
        }
        cout << "\n";
    }

    int result = 0;
    for(int i = 1; i <= 3000; i++) {
        result += dp[n-1][i];
    }

    cout << result << "\n";

    return 0;
}
