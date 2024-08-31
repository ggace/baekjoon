#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(){
    fio;

    ull n;

    cin >> n;

    int before_number = n % 10;

    n /= 10;

    int term = n%10 - before_number;

    while(true) {
        if(n == 0) {
            break;
        }

        if(n%10 - before_number != term) {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << "\n";
            return 0;
        }

        before_number = n%10;
        n /= 10;
    }

    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";



    return 0;
}
