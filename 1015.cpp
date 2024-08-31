#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    int n;
    
    cin >> n;

    int arr[50] = {0, };
    int temp[50] = {0, };


    for(int i = 0; i < n; i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    

    sort(temp, temp+n);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] == temp[j]){
                cout << j << " ";
                temp[j] = -1;
                break;
            }
        }
    }

    return 0;
}