#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b) for(int i = a; i < b; i++) 
#define foreach(l) for(auto ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

using namespace std;

struct Thing {
    int mess;
    int value;
    Thing(int m, int v) : mess(m), value(v) {}
    
};

priority_queue<Thing> things;
vector<int> weights;

bool reverse_compare(int a, int b) {
    return a > b;
}

ll result = 0;

int main(int argc, char* argv[]) {
    //fio;

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        things.push(Thing(m, v));
    }
    for(int i = 0; i < k; i++) {
        int w;
        cin >> w;
        weights.push_back(w);
    }

    return 0;
}
