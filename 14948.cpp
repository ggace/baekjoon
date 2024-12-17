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

int n, m;
vector<vector<int>> levels(101, vector<int>(101, 0));
int result[101][101][2];

struct node {
    int level;
    int colum;
    int row;
    int jump_count;

    node(int l, int c, int r, int j):  level(l), colum(c), row(r), jump_count(j) {}

    bool operator<(const node& node)const {

		return level > node.level;
	}
};

bool visited[101][101][2];

Direction direction[4] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

bool check_area(int col, int row) {
    return (col >= 0 && col < n) && (row >= 0 && row < m);
}

void bfs() {
    priority_queue<node> pq;

    pq.push(node(levels[0][0], 0, 0, 1));

    while(!pq.empty()) {
        auto [level, column, row, jump_count] = pq.top();
        pq.pop();

        

        if(visited[column][row][jump_count]) {
            continue;
        }
        debug( "(" << column << ", "  << row << ") : " << level << "(" << jump_count << "): " << "\n");
        visited[column][row][jump_count] = true;
        result[column][row][jump_count] = level;

        for(int i = 0; i < 4; i ++) {
            int next_column = column + direction[i].dx;
            int next_row = row + direction[i].dy;
            if(check_area(next_column, next_row)) {
                pq.push(node(max(levels[next_column][next_row], level), next_column, next_row, jump_count));
                
                debug("+ (" << next_column << ", " << next_row << ") : " << max(levels[next_column][next_row], level) << " (" << jump_count << ")\n");
            }
            
        }
        if(jump_count == 0) {
            continue;
        }
        for(int i = 0; i < 4; i ++) {
            int next_column = column + direction[i].dx*2;
            int next_row = row + direction[i].dy*2;
            if(check_area(next_column, next_row)) {
                pq.push(node(max(levels[next_column][next_row], level), next_column, next_row, jump_count-1));

                debug("+ (" << next_column << ", " << next_row << ") : " << max(levels[next_column][next_row], level) << " (" << jump_count-1 << ")\n");
            }
        }
    }
    
}

int main(int argc, char* argv[]) {
    fio; 

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            cin >> levels[i][j];
        }
    }

    bfs();

    cout << min(result[n-1][m-1][0], result[n-1][m-1][1]);

    return 0;
}
