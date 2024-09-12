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
    
    bool operator<(const Thing & a)const {
        if(value == a.value) {
            return mess > a.mess;
        }
		return value < a.value;
	}
};

priority_queue<Thing> things;
multiset<int> weights;

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
        weights.insert(w);
    }

    while(!things.empty() && ! weights.empty()) {
        auto [mess, value] = things.top();
        //cout << "{" << mess << ", " << value <<"}\n";
        things.pop();

        auto iter = weights.lower_bound(mess);
        if(iter  == weights.end()) {
            continue;
        }

        result += value;

        //cout << *iter << "\n";



        weights.erase(iter);
    }

    cout << result << "\n";

    return 0;
}
