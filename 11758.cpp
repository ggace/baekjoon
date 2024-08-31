#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(int argc, char* argv[]) {
    fio;

    int x1, x2, x3;
    int y1, y2, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    pair<int, int> vec1 = {x2-x1, y2-y1};
    pair<int, int> vec2 = {x3-x1, y3-y1};

    int det = vec1.first * vec2.second - vec1.second * vec2.first;

    cout << (det > 0) - (det < 0) << "\n";

    return 0;
}
