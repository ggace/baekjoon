#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <deque>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

vector<ll> v;

int main(){
    fio;

    int n;

    cin >> n;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    ll count = 0;
    while(!v.empty()) {
        ll tmp = v[0];
        //cout << tmp;
        if(count == n-1) {
            cout << tmp << "\n";
            return 0;
        }

        v.erase(v.begin());

        for(int i = 0; i < tmp % 10; i++) {
            ll number = tmp * 10 + i;

            v.push_back(number);
        }
        count++;
    }
    
OUT:
    
    cout << "-1\n";
    
    return 0;
}
