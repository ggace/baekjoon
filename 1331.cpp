#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int is_visited[6][6];

int main(){
    fio;
    
    int n = 35;

    char initial_c;
    int  initial_r;
    int before_movement = 5;
    char before_c;
    int before_r;
    char c;
    int r;

    cin >> c >> r;

    before_c = c;
    before_r = r;

    initial_c = c;
    initial_r = r;

    is_visited[c-'A'][r] = 1;

    while(n--) {
        cin >> c >> r;        

        int c_move = before_c-c;
        int r_move = before_r-r;

        //cout << c_move << " " <<  r_move << ": " << (c_move * c_move + r_move * r_move) << "\n";
        if((c_move * c_move + r_move * r_move) ^ 5) {
            cout << "Invalid\n";
            return 0;
        }
        if(is_visited[c-'A'][r]){
            cout << "Invalid\n";
            return 0;
        }
        is_visited[c-'A'][r] = 1;

        before_c = c;
        before_r = r;
    }

    if((c -initial_c) * (c -initial_c) + (r -initial_r) * (r -initial_r) ^ 5) {
        cout << "Invalid\n";
        return 0;
    }
    cout << "Valid\n";

    return 0;
}
