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

    float a, b, c, i, j, k;

    cin >> a >> b >> c;
    cin >> i >> j >> k;

    float minimum_cup = min(min(a / i, b / j), c / k);

    printf("%.6f %.6f %.6f", a - minimum_cup * i, b - minimum_cup * j, c - minimum_cup * k);
    cout << "\n";

    return 0;
}
