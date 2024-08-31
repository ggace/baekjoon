#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int arr[11] = {0, };
int result[11] = {0, };

vector<int> v = {0,1,2,3,4,5,6,7,8,9};

int main(){
    
    fio;

    int n; 

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        int index = v[arr[i]];
        //cout << index << "\n";
        result[index] = i+1;

        v.erase(v.begin()+arr[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    cout << "\n";





    return 0;
}
