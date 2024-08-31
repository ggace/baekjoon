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
    string s;

    

    

    while(true){

        stack<char> stk;
        stk.push('a');

        int result = 0;

        getline(cin, s);

        if(s == "."){
            break;
        }

        if(s[s.size() -1 ] != '.'){
            cout << "no"<< "\n";
            continue;
        }

        bool trigger = true;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '['){
                
                stk.push(s[i]);
            }
            else if(s[i] == ')'){
                if(stk.top() == '('){
                    
                    stk.pop();
                }
                else {
                    cout << "no" << "\n";
                    trigger = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(stk.top() == '['){
                    
                    stk.pop();
                }
                else {
                    cout << "no" << "\n";
                    trigger = false;
                    break;
                }
            }
        }

        if(trigger){
            if(stk.size() == 1)
                cout << "yes" << "\n";
            else 
                cout << "no" << "\n";
        }
        
    }
    
    return 0;
}