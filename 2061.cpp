#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string k;
    int l;

    cin >> k >> l;

    int temp = 0;

    for(int i = 2; i < l; i++){
        temp = 0;
        for(int j = 0; j < k.size();j++){
            temp += k[j] - '0';

            temp = temp % i * 10;

            
        }
        if(!temp){
            cout << "BAD " << i;
            return 0;
        }
    }

    cout << "GOOD";

    return 0;

}
