#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 0; i < 2*n-1; i++) {
        for(int j = 0; j < n-1 - abs(i-n+1); j++) {
            cout << " ";
        }
        for(int j = 0; j < abs(n-1-i)*2+1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
