#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

void go() {
    int t;
    ll arr[100000+1];
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+t);

    ll current_number = arr[0];
    int current_number_count = 0;

    ll maximum_count_number = arr[0];
    int maximum_count_number_count = 0;

    for(int i = 0; i < t; i++){
        
        if(current_number != arr[i]){
            current_number = arr[i];
            current_number_count = 0;
        }

        
        current_number_count++;
        

        if(current_number_count > maximum_count_number_count){
            maximum_count_number = current_number;
            maximum_count_number_count = current_number_count;
        }
    }


    if(maximum_count_number_count > t/2){
        cout << maximum_count_number << "\n";
        return;
    }

    cout << "SYJKGW\n";
    
    return;
}

int main() {
    fio();
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        go();
    }

    return 0;
}