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
int parent[1010101];

int find(int x) {
    if(parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    parent[a] = b;
}

int main(int argc, char* argv[]) {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if(!o) {
            Union(a, b);
        }
        else {
            if (find(a)==find(b)) cout << "YES\n";

            else cout << "NO\n";

        }
    }

    return 0;
}
