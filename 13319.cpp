#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define loop(a, b, type, i) for(type i = a; i < b; i++) 
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

vector<ll> prime_list;
vector<ll> under_500_prime_list;
bool is_prime[31622777+1] = {1,1,0}; // 0이 소수
void siv(ll n) {
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) {
            prime_list.push_back(i); 
            if(i <= 500) 
                under_500_prime_list.push_back(i);
        }
        for(auto p : prime_list) {
            if(i*p > n) break;
            is_prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}

int main(int argc, char* argv[]) {
    fio;

    siv(555);
    ll n = 281861;
    for(auto a: under_500_prime_list) {
        if(!(fastpow(a, n-1, n) == 1)) {
            cout << "no at " << a << "\n";
            exit(0);
        }
    }

    cout << "yes\n";


    return 0;
}
