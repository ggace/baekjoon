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

    sort(v.begin(), v.end(), reverse_compare);

    for(int i = 0; i < n-2; i++) {
        if(v[i] < v[i+1] + v[i+2]) {
            cout << v[i] + v[i+1] + v[i+2] << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}
