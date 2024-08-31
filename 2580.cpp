#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

pair<int, int> board[10][9];
pair<int, int> final_board[10][9];

int main(int argc, char* argv[]) {
    fio;

    memset(board, -1, 90 * sizeof(pair<int, int>));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int t;

            cin >> t;

            if(t == 0) {
                continue;
            }
            board[t][i] = {j, j/3};

            
        }
    }

    

    return 0;
}
