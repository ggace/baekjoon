#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[101010];

bool is_prime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    fio;

    int a, b;
    int count = 0;

    cin >> a >> b;

    for(int i = 1; i <=b; i++) {
        int result = 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                result = dp[i/j] + 1;
                break;
            }
        }
        dp[i] = result;
        //cout << i << ": "  << result << "\n";
        if(i >= a && is_prime(result)) {
            count++;
        }
    }

    cout << count;



    return 0;
}
