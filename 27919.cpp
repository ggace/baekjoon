#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(){
    fio;

    string s;

    cin >> s;


    int uc = 0;
    int dp = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'U' || s[i] == 'C' ) {
            uc ++;
        }
        else if(s[i] == 'D' || s[i] == 'P') {
            dp++;
        }
    }

    cout << uc << " " << dp;

    cout << "\n";

    if(uc > (int)(dp/2.+0.5)) {
        cout << "UDP\n";
    }
    else {
        cout << "DP\n";
    }

    return 0;
}
