#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int arr[1010];

int main(){
    //fio;

    int n = 0;
    cin >> n;

    while(n--) {
        int a;
        
        cin >> a;

        int max = 0;

        for(int i = a-1; i >= 0; i--) {
            if(max < arr[i]) {
                max = arr[i];
            }
        }

        arr[a] = max+1;

        
        //cout << arr[a] << "\n";
    }

    int max = 0;
    for(int i = 0; i <= 1000; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    cout << max << "\n";

    
    return 0;
}
