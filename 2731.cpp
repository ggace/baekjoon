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

__int128_t fastpow(__int128_t a, __int128_t n, __int128_t c){
    __int128_t result=1;
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

map<int, int> first;
map<int, vector<int>> digits;

void solution() {
    string p;
    __int128_t result = 0;

    cin >> p;

    __int128_t digit_count = fastpow(10, p.size(), 10000000000+1);
    ll s = stoll(p);

    result += first[s % 10];
    int first_digit = s % 10;

    __int128_t count = 10;

    while(true) {
        ll current_diff = (s + digit_count - fastpow(result, 3, digit_count));
        
        if(current_diff % digit_count == 0) {
            break;
        }

        result += digits[first_digit][(current_diff / count) % 10] * count;
        
        count *= 10;


    }

    cout << (ll)result << "\n";


}

int main(int argc, char* argv[]) {
    fio;

    int t;

   cin >> t;

   first[1] = 1;
   first[3] = 7;
   first[7] = 3;
   first[9] = 9;

   digits[1] = {0,7,4,1,8,5,2,9,6,3};
   digits[3] = {0,3,6,9,2,5,8,1,4,7};
   digits[7] = {0,3,6,9,2,5,8,1,4,7};
   digits[9] = {0,7,4,1,8,5,2,9,6,3};


    while(t--) {
        solution();
    }

    return 0;
}
