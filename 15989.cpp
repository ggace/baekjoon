#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int arr[10000];

int main(int argc, char* argv[]) {
    fio;

    int t;

    cin >> t;

    for(int i = 0; i <= 10000; i++) {
        int n = i+2;

        for(int j = 0; ; j++) {
            if(n/2 == 0) {
                break;
            }

            arr[i] += n/2;
            n -= 3;
        }
    }

    while(t--) {
        int a;

        cin >> a;

        cout << arr[a] << "\n";
    }

    return 0;
}
