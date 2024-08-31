#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int dp[1000000] = {1,2};

int main(){
    fio;

    int n;

    cin >> n;

    int a = 1, b = 2;

    switch(n){
        case 1:
            cout << "1\n";
            break;
        
    }

    for(int i = 4; i < n; i++) {
        int temp = b;
        b = a + b;
        a = b;
    }

    cout << a + b << "\n";

    return 0;
}
