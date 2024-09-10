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

bool reverse_compare(ll a, ll b) {
    return a > b;
}

vector<ll> positive_number_without_1;
ll one_count = 0;
ll zero_count = 0;
vector<ll> negative_number;

ll result = 0;

int main(int argc, char* argv[]) {
    //fio;

    int n;

    cin >> n;

    while(n--) {
        ll k;

        cin >> k;

        if(k == 1)  {
            ++one_count;
            continue;
        }
        if(k == 0) {
            ++zero_count;
            continue;
        }
        if(k > 1) {
            positive_number_without_1.push_back(k);
            continue;
        }
        if(k < 0) {
            negative_number.push_back(k);
            continue;
        }
    }

    sort(negative_number.begin(), negative_number.end());
    sort(positive_number_without_1.begin(), positive_number_without_1.end(), reverse_compare);

    ll n_size = negative_number.size();
    if(n_size % 2) {
        if(!zero_count) {
            result += negative_number[n_size-1];
        }        
        --n_size;
    }
    for(int i = 0; i < n_size; i += 2) {
        result += negative_number[i] * negative_number[i+1];
    }

    ll p_size = positive_number_without_1.size();
    
    if(p_size % 2) {
        
        result += positive_number_without_1[p_size-1];
        --p_size;
    }
    for(int i = 0; i < p_size ; i += 2) {
        result += positive_number_without_1[i] * positive_number_without_1[i+1];
    }

    result += one_count;

    cout << result << "\n";
    

    return 0;
}
