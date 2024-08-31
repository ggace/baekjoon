#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

string s;
string find_str;
int find_str_length;

void go() {
    
    int n = s.find(find_str);

    if(n == string::npos){

        if(!s.length()){
            cout << "FRULA\n";
            return;
        }

        cout << s << "\n";
        return;
    }

    s.erase(n, find_str_length);

    go();
}

int main(){
    fio();

    cin >> s >> find_str;

    find_str_length = find_str.length();

    int n = s.find(find_str);

    go();

    return 0;
}