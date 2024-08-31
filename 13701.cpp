//baekjoon 13701
//I try to use vim to adjust vim well by solving baekjoon problem
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<char> arr(33554432/8+1);

int main(int argc, char* argv[]) {
    
    fio;
    int a;

    while(cin >> a){
        int index = a / 8;
        int bit_shift = a % 8;
        
        if(!((arr[index] >> bit_shift) & 0b1)) {
            cout << a << " ";
            arr[index] |= (0b1 << bit_shift);

        }
    }


    return 0;
}
