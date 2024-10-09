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

vector<vector<int>> v(501);
int arr[555][555];

int main(int argc, char* argv[]) {
    fio;

    int n;cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int a;
            cin >> a;

            v[i].push_back(a);
        }
    }

    arr[0][0] = v[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            arr[i][j] = max(v[i][j] + arr[i-1][j], v[i][j] + arr[i-1][j-1]);
            
            
        }
        
    }

    int max = -1;
    for(int i = 0; i < n; i++) {
        if(max < arr[n-1][i]) {
            max = arr[n-1][i];
        }
    }

    cout << max << "\n";

    return 0;
}
