#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

//9 4 3 1
//85 4

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}


int main(){
    fio;

    ll G, T, A, D;

    while(true) {
        cin >> G >> T >> A >> D;

        //G*A/T+D=X+Y

        if(G == -1 && !(G ^ T ^ A ^ D)) {
            break;
        }

        ll tmp_G = G;

        ll X = T * (T - 1) / 2 * G;
        ll Y;

        //G * A + D
        G = pow(2, ceil(log2(G * A + D))) / 2;

        //cout << G << "\n";
        /*if(D > 0) {
            G *= 2;
        }*/
        if(G == 0) {
            Y = 0;
            cout << tmp_G << "*" << A << "/" << T << "+" << D << "=" << X << "+" << Y << "\n";
            continue;
        }
        X += G*2 - 1; //X += G - 1; 
        Y = G*2 - tmp_G*A - D;

        cout << tmp_G << "*" << A << "/" << T << "+" << D << "=" << X << "+" << Y << "\n";
        
    }


    return 0;
}