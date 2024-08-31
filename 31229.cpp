#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}


int main(){
    fio;

    int n;

    cin >> n;

    int cnt=0;

    for(int i = 1; cnt < n; i++) {
        if(i%2) {
            cout << i << " ";
            cnt++;
        }
        
    }

    cout << "\n";

    return 0;
}
