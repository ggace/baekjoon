#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int main(){
    fio;

    string s;

    cin >> s;

    int state = 0;
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ')') {
            if(!state) {
                count++;
            }
            else {
                state -= 1;
            }
        }
        if(s[i] == '(') {
            state += 1;
        }
    }

    count += state;

    cout << count << "\n";

    return 0;
}
