#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    string str;

    cin >> str;

    bool sumable = true;

    ll n = -1;

    ll result = 0;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            sumable = true;
            n ++;
        }
        else if(str[i] == ')'){
            
            if(sumable){
                result += n;
            }
            n--;
            sumable = false;
        }
    }

    cout << result << "\n";

    return 0;
}