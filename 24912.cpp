#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int arr[1000000];

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 1; i <= n;i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        if(arr[i-1] == arr[i] && arr[i] != 0) {
            cout << "-1\n";
            return 0;
        }
    }

    arr[0] = 1;

    for(int i = 1; i <= n;i++ ) {
        if(arr[i]) {
            continue;
        }
        if(arr[i-1] == arr[i+1] && arr[i-1] != 0) {
            if(arr[i-1] == 3) {
                arr[i] = 1;
                continue;
            }
            arr[i] = (0b11 ^ arr[i-1]) & 0b11;
            continue;
        }
        if(arr[i-1] && arr[i+1]) {
            arr[i] = arr[i-1] ^ arr[i+1];
            continue;
        }

        if((arr[i-1] ^ 0b11) & 0b11) {
            arr[i] = (0b11 ^ arr[i-1]) & 0b11;
            continue;
        }
        if(arr[i-1] == 3) {
            arr[i] = 1;
            continue;
        }
        
        

    }

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";


    return 0;
}
