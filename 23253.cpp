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

    int n;

    cin >> n;
    int m;
    cin >> m;

    while(m--) {
        int k;
        cin >> k;

        int a;

        int back_number;

        cin >> a;

        back_number = a;

        k--;
        while(k--) {
            cin >> a;
            if(back_number < a) {
                cout << "No\n";
                return 0;
            }
            back_number = a;
        }



    }

    cout << "Yes\n";



    return 0;
}
