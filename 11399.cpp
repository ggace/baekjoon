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

vector<int> v;

int main(){
    fio;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    

    for(int i = 1; i < n; i++) {
        v[i] = v[i] + v[i-1];
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        result += v[i];
    }

    cout << result << "\n";

    return 0;
}
