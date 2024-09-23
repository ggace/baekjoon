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

bool prime_check[1010101] = {1,1,0};
vector<ll> prime;

void siv(int n) {
    for(int i = 2; i <= n; i++) {
        if(!prime_check[i]) prime.push_back(i);
        
        for(auto p : prime) {
            if(p > i) break;
            if(p * i > n) break;
            prime_check[i * p] = 1;   
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    siv(100'000'000);

    lower_bound(prime.begin(), prime.end(), n);



    return 0;
}
