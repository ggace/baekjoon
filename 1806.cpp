#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, i) for(i = a; i < b; i++) 
#define foreach(l, ele) for(ele : l)
#define println(s) cout << s << "\n"
#define mp() make_pair()

#include <bits/stdc++.h>

using namespace std;

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

vector<int> v;

int main(int argc, char* argv[]) {
    fio;

    int n, s;

    cin >> n >> s;

    while(n--) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int start = 0, end = 0;

    int sum = 0;

    for(int i = start; i <= end; i++) {
        sum += v[i];
    }

    while(true){
        if(end == v.size()-1) {
            break;
        }
        if(sum < s) {
            ++end;
            sum += v[end];
        }
        if(sum > s) {
            cout << end-start+1 << '\n';
            return 0;
        }
    }

    cout << "0\n";
    


    


    return 0;
}
