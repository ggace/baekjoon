#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

vector<int> v;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}


int main(){
    fio;

    int n,k;

    cin >> n >> k;

    int cnt = 0;

    for(int i =0; i < n; i++) {
        int tmp;

        cin >> tmp;

        v.push_back(tmp);
    }

    for(int i = n-1; i >= 0; i--) {
        if(v[i] > k) {
            continue;
        }
        int current_cnt = (int)(k / v[i]);
        k -= current_cnt * v[i];

        cnt += current_cnt;

        if(k == 0) {
            break;
        }

    }

    cout << cnt << "\n";

    return 0;
}
