#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

map<ull, ull> v = {{0, 1}};
ull p, q;

ull go(ull n) {
    if(n == 0) {
        return 1;
    }
    if(v[n]) {
        return v[n];   
    }    

    return v[n] = go(n/p) + go(n/q);
}

int main(){
    //fio;

    ull n;

    cin >> n >> p >> q;

    cout << go(n) << "\n";
/*
    for(ull i = n; i >= 0;i /= 2) {
        if(i < SIZE)
            cout << i << ":" << v[i] << "\n";
        if(i == 0) {
            break;
        }
    }
*/
    return 0;
}
