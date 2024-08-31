#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio;

    int n;

    cin >> n;

    int arr[1000000];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int before_value = arr[0];
    int cnt = 0;

    for(int i = 1; i < n; i++) {
        if(before_value >= arr[i]) {
            cnt++;
        }

        before_value = arr[i];
    }

    if(arr[0] <= arr[n-1]) {
        cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
