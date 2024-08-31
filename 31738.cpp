#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}


int main(){
    fio;


    ll n, m;
    ll result = 1;

    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        result *= i;

        if(result > m) {
            result %= m;
        }
    }

    cout << result << "\n";

    return 0;
}
