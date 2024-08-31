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

    int n;

    cin >> n;

    for(int i = n; i>= 1; i--) {
        for(int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;   
}
