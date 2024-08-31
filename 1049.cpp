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

    int result = 0;

    int n, m;

    cin >> n >> m;

    int package = n/6;
    int rest = n%6;

    int min_6 = 0x7fffffff-1;
    int min_1 = 0x7fffffff-1;

    for(int i = 0; i < m; i++) {
        int pkg_money, rest_money;

        cin >> pkg_money >> rest_money;

        if(min_6 > pkg_money) {
            min_6 = pkg_money;
        }
        if(min_6 > rest_money*6) {
            min_6 = rest_money*6;
        }
        if(min_1 > rest_money) {
            min_1 = rest_money;
        }
    }

    result += min_6 * package;
    if(min_1 * rest > min_6) {
        result += min_6;
    }
    else {
        result += min_1 * rest;
    }

    cout << result << "\n";

    return 0;
}
