#define fio cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

int main() {
    fio;
    
    ll n;
    cin >> n;

    int first = 0;
    int second = 1;
    int result;

    if(n == 0) {
        cout << "0\n";
        return 0;
    }
    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    

    --n;

    while(n--) {
        result = (first % 1000000 + second % 1000000) % 1000000;
        
        first = second;
        second = result;
        //cout << (first + second) % 1000000 << "\n";
    }

    cout << result << "\n";

    return 0;
}
