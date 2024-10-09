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

vector<ll> positive_number;
vector<ll> negative_number;
bool zero = false;

int main(int argc, char* argv[]) {
    fio;

    ll n;
    cin >> n; 

    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        if(a > 0) {
            positive_number.push_back(abs(a));
        }
        else if(a < 0) {
            negative_number.push_back(abs(a));
        }
        else {
            zero = true;
        }
    }

    sort(negative_number.begin(), negative_number.end());
    sort(positive_number.begin(), positive_number.end());

    pii minimum = {0,0};
    ll minimum_result = LONG_LONG_MAX;

    for(ll i = 0; i < positive_number.size(); i++) {
        ll p = positive_number[i];
        ll n_index = lower_bound(negative_number.begin(), negative_number.end(), p) - negative_number.begin();        

        if(n_index == negative_number.size()) {
            if(minimum_result > abs(p - negative_number[n_index-1])) {
                minimum = {p, negative_number[n_index-1]};
                minimum_result = abs(p - negative_number[n_index-1]);
            }
            continue;
        }
        
        if(n_index == 0) {
            if(minimum_result > abs(p - negative_number[0])) {
                minimum = {p, negative_number[0]};
                minimum_result = abs(p - negative_number[0]);
            }
            continue;
        }

        if(minimum_result > abs(p - negative_number[n_index])) {
            minimum = {p, negative_number[n_index]};
            minimum_result = abs(p - negative_number[n_index]);
        }
        if(minimum_result > abs(p - negative_number[n_index-1])) {
            minimum = {p, negative_number[n_index-1]};
            minimum_result = abs(p - negative_number[n_index-1]);
        }
        




    }

    cout << minimum.first << " " << -minimum.second << "\n";



    return 0;
}
