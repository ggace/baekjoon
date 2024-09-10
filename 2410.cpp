#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b) for(int i = a; i < b; i++) 
#define foreach(l) for(auto ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

using namespace std;

#define REST (int)1e9
int  dp[1010101][21] = {1};
int result = 0;

int main(int argc, char* argv[]) {
    //fio;

    int n;

    cin >> n;

    for(int i = 1; i <= n/2 + 1; i++) {
        // cout << i-1 << " : ";
        float l = log2(i);
        int temp = 1;
        for(int j = 0; j < l+1; j++) {
            temp *= 2;
            if((j == 0)) {
                dp[i][j] = 1;
                // cout << dp[i][j] << " ";
                continue;
            }
            if(j == 1) {
                dp[i][j] = (1 + dp[i-1][j]) % REST;
                // cout << dp[i][j] << " ";
                continue;
            }

            dp[i][j] = (dp[i-(temp/8)][j-1] + dp[i-(temp/8)* 2][j]) % REST;
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";

    }

    
    for(int i = 0; i < 21; i++) {
        result = (result + dp[n/2+1][i]) % REST;
    }

    cout << result << "\n";    

    return 0;
}
