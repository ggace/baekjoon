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

bool is_prime[10000001] = {1,1,0};

int result = 0;


vector<int> ps;
int n;
bool np[10000001];

void siv(){
    np[1]=1;
    for(int i=2;i<=n;i++){
        if(!np[i]) ps.push_back(i);
        for(auto j:ps){
            if(i*j>n) break;
            np[i*j]=1;
            if(i%j==0) break;
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    int a, b;

    cin >> a >> b;

    for(int i = 2; i <= b; i++) {
        if(is_prime[i]) {
            continue;
        }
        
        for(int j = 2; i * j <= b; j++) {
            is_prime[i*j] = true;
        }
    }

    for(int i = a; i <= b; i++) {
        if(!is_prime[i]) {
            cout << i << "\n";
        }
    }
    

    return 0;
}
