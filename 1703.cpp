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

    while(true) {
        int result = 1;
        int index = 0;
        int n;

        cin >> n;
        if(n == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            int m;
            int p;
            cin >> m >> p;
            result *= m != 0? m : 1;
            result -= p;
        }

        cout << result << "\n";

        

    }

    return 0;
}
