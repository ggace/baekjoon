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

ll my_pow(ll a, ll b, ll c) {
    if(b == 1) {
        return a % c;
    }
    ll t = my_pow(a, b/2, c);
    ll ret = ((t%c) * (t%c)) % c;

    //cout << b << ": " << ret << "-" << t << "\n";
    if(b % 2) {
        return (ret * (a % c)) % c;
    }
    return ret;
}

using namespace std;

int main(int argc, char* argv[]) {
    fio;

    int a, b, c;

    cin >> a >> b >> c;

    cout << my_pow(a, b, c);

    return 0;
}
