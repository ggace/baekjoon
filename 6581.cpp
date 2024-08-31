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

    string str;

    while(!cin.eof()) {
        char c;
        cin >> c;

        if(c == '<') {
            char a,b,c;
            cin >> a>> b >> c;

            if(a == 'b') {
                str += '\n';
                continue;
            }
            else if(a == 'h') {
                str += "\n--------------------------------------------------------------------------------\n";
                continue;
            }
        }
        str += c;

        if(c == '_') {
            break;
        }
    }

    cout << str;

    return 0;
}
