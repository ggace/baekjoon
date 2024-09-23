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

bool visited[9 * 1010101];

int main(int argc, char* argv[]) {
    fio;

    ll n;

    cin >> n;

    n *= 9;

    int temp = 10 % n;
    ll result = 1;
    visited[temp] = true;

    while(true) {
        if(temp == 1) {
            cout << result << "\n";
            break;
        }
        
        temp = ((10 % n) * (temp % n)) % n;
        if(visited[temp]) {
            cout << "-1\n";
            break;
        }
        visited[temp] = true;
        result++;
    }



    return 0;
}
