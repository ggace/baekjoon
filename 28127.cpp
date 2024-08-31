#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    int q;

    cin >> q;

    while(q--) {
        ll a, d, x;

        cin >> a>> d >> x;

        int n = ( d/2. -a + sqrt( (a-d/2.) * (a-d/2.) + 2* d * x ) ) / d;

        ll Sn = d / 2. * n * n + (a - d/2.) * n;

        if(Sn == x) {
            n--;
            Sn = d / 2. * n * n + (a - d/2.) * n;
        }

        
        cout << n+1 << " "<< x - Sn << "\n";
    }

    return 0;
}