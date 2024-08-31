#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef long double ld;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define expression_count 15

using namespace std;

bool reverse_compare(ll i1, ll i2) {
    return i1 > i2;
}


int main(){
    //fio;

    ld N, L, W, H;

    cin >> N >> L >> W >> H;

    ld min = 0;
    ld max = 1e10;

    
    ld current;
    
    ll count = 1000000;
    cout << fixed;
    cout.precision(10);
    while(count--) {
        
        current = (min + max) / 2.;
        
        if((ll)(L / current) * (ll)(W / current) * (ll)(H / current) < N) {
            
            max = current;
        }
        else {
            min = current;
        }
    }

    cout << current << "\n";

    return 0;
}
