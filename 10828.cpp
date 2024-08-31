#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <stack>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    stack<int> s;
    int n;
    cin >> n;

    while(n--){
        string cmd;

        cin >> cmd;
        if(cmd == "push"){
            int n;
            cin >> n;

            s.push(n);
        }
        else if(cmd == "pop"){
            if(s.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }

        else if(cmd == "size"){
            cout << s.size() << "\n";
        }
        else if(cmd == "empty") {
            cout << (int)s.empty() << "\n";
        }
        else if(cmd == "top"){
            if(s.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}