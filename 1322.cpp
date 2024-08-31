#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool reverse_compare(ll i1, ll i2) {
    return i1 > i2;
}

int main(){
    fio;

    ll x, k;

    cin >> x >> k;

    ll reverse_x = ~x;
    ll result = 0;

    ll index = 0;

    for(int i = 0; i < 64; i++) {

        if(!(reverse_x & 1)) {
            index++;
            reverse_x >>= 1;
            continue;
        }

        result += ((1&k) << index);

        //cout << ((1&k) << index) << "\n";
        index++;

        reverse_x >>= 1;
        k >>= 1;

    }

    cout << result << "\n";
    
    return 0;
}
