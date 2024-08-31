#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <algorithm>
#include <stack>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){

    stack<int> s;

    fio();

    int k;

    cin >> k;

    while(k--){
        int n;

        cin >> n;

        if(n == 0){
            s.pop();
        }
        else {
            s.push(n);
        }

        

        
    }
    
    int sum = 0;
    int size = s.size();
    for(int i = 0; i < size; i++){
        sum += s.top();
        s.pop();
    }

    cout << sum << "\n";

    return 0;
}