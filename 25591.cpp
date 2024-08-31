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

    int n,m;

    cin >> n >> m;

    int a = 100-n;
    int b = 100-m;
    int c = 100 - (a+b);
    int d = a*b;

    int q = d / 100;
    int r = d % 100;

    char buffer[100];

    int P, Q;

    P = q+c;
    Q = r;
    
    sprintf(buffer, "%d %d %d %d %d %d\n%d %d\n", a, b, c, d, q, r, P, Q);

    cout << buffer  ;

    return 0;
}
