#include <iostream>

using namespace std;

int main(){

    int e, s, m;

    cin >> e >> s >> m;

    int n;

    for(int x = 0; ; x++){
        int rest = (15 * x + e - s) % 28;
        if(!rest) {
            n = 15 * x + e;
            break;
        }
    }

    for(int i = 0; ; i++){
        if(!((n + 420 * i - m) % 19)){
            printf("%d", n+420 * i);
            break;
        }
    }

    

    return 0;
}