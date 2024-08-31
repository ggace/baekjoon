#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

vector<int> a;
vector<int> b;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(){
    fio;

    int n, k;

    cin >> n;

    for(int i =0; i < n; i++) {
        cin >> k;

        a.push_back(k);
    }

    for(int i =0; i < n; i++) {
        cin >> k;

        b.push_back(k);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), reverse_compare);


    int result = 0;

    for(int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    cout << result << "\n";
    

    return 0;
}
