typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
#define println(s) cout << s << "\n"
#define mp() make_pair()
#define PRIME_SIZE 5
#define PIE M_PIf64
#define arri(n) array<int, n>
#define arrl(n) array<ll, n>
#define input(type, value) type value; cin >> value;

#ifdef BOJ
#define debug(x)  ((void)0);
#define debug_value(x)  ((void)0);
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#else
#define debug(x)  cout << "[Debug] " << x;
#define debug_value(x)  cout << "[Debug] " << #x << " is " << x << '\n';
#define fio ((void)0);
#endif

#include <bits/stdc++.h>

using namespace std;

class Direction {
    public:
        int dx;
        int dy;
};

class Position {
    public:
        int x;
        int y;
};

ll fastpow(ll a, ll n, ll c){
    ll result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=c) result%=c;
        }
        a*=a;
        if(a>=c) a%=c;
        n>>=1;
    }
    return result;
}

vector<ll> prime_list;
bool is_prime[PRIME_SIZE+1] = {1,1,0}; // 0이 소수
void siv(ll n) {
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) prime_list.push_back(i);
        for(auto p : prime_list) {
            if(i*p > n) break;
            is_prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}

int sudoku[9][9];
bool sudoku_vertical[10][9];
bool sudoku_horizontal[10][9];
bool sudoku_section[10][9];

void fill_sudoku(int col, int row) {
    for(int i = 1; i <= 9; i++) {
        // debug("(" << col << ", " << row << "): " << i << "\n");
        

        if(!sudoku_vertical[i][col] && !sudoku_horizontal[i][row] && !sudoku_section[i][3* (int)(col/3) + (int)(row/3)]) {
            sudoku[col][row] = i;
            sudoku_vertical[i][col] = true;
            sudoku_horizontal[i][row] = true;
            sudoku_section[i][3* (int)(col/3) + (int)(row/3)] = true;
            break;
        }
        
    }
}

int main(int argc, char* argv[]) {
    fio;

    loop(0, 9, int, i) {
        loop(0, 9, int, j) {
            int a;
            cin >> a;
            if(a == 0) {
                continue;
            }
            sudoku[i][j] = a;
            sudoku_vertical[a][i] = true;
            sudoku_horizontal[a][j] = true;
            sudoku_section[a][(int)(j/3) + 3 * (int)(i/3)] = true;
            // debug(a << ": " << (int)(j/3) + 3 * (int)(i/3) << "\n") ;
        }
    }

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(sudoku[i][j] == 0) {
                fill_sudoku(i, j);
            }

            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
