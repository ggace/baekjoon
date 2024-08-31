#include <iostream>

using namespace std;

int main() {
    int n, m;

    if(m == 0) {
        cout << "0\n" << n << "\n";
    }
    
    cin >> n >> m;
    
    cout <<(int) (n / m)  << "\n" << n%m << "\n";
}