#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <list>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    string str;
    list<char> l;
    
    cin >> str;

    for(int i = 0; i < str.length(); i ++) {
        l.push_back(str[i]);
    }

    int n;

    cin >> n;

    list<char>::iterator cur = l.end();

    for(int i = 0; i < n; i++) {

        char cmd;

        cin >> cmd;

        if(cmd == 'L'){
            if(cur == l.begin()) {
                continue;
            }
            cur--;
        }
        else if(cmd == 'D'){
            if(cur == l.end()) {
                continue;    
            }
            cur++;
            
        }
        else if(cmd == 'B'){
            if(cur == l.begin()) {
                continue;
            }
            l.erase(--cur++);
            cur--;
        }
        else if(cmd == 'P'){
            char c;

            cin >> c;

            l.insert(cur, c);
            //cur++;
        }
        

    }
    for(list<char>::iterator i = l.begin(); i != l.end(); i++) {
        cout << *i;
    }
    cout << "\n";
    
    

    return 0;
}