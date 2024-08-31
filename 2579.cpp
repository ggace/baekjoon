#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[333][3];
vector<int> v;

int main(){
    fio;

    int n;

    cin >> n;
    for(int i = 0; i <n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    //cout << "end\n" ;

    memset(dp, -1, sizeof(int) * (n+1) * 3);

    dp[0][1] = v[0];
    dp[1][1] = v[1];


    for(int i = 1; i < n; i++) {
        if(i == 1) {

        }
        else if(dp[i-1][0] == -1) {
            dp[i][1] = -1;
        }
        else {
            dp[i][1] = dp[i-1][0] + v[i];
        }

        if(dp[i-1][1] == -1) {
            dp[i][2] = -1;
        }
        else{
            dp[i][2] = dp[i-1][1] + v[i];
        }

        if(dp[i-1][2] == -1 && dp[i-1][1] == -1) {
            dp[i][0] = -1;
        }
        else if(dp[i-1][2] == -1){
            dp[i][0] = dp[i-1][1];
        }
        else if(dp[i-1][1] == -1) {
            dp[i][0] = dp[i-1][2];
        }
        else {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        }

        //cout << v[i] << "\t | " << dp[i][0] << " \t" << dp[i][1] << " \t" << dp[i][2] << "\n";
    }

    dp[n-1][0] = -1;

    cout << max(dp[n-1][1], dp[n-1][2]) << "\n";

    return 0;
}
