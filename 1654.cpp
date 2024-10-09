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

vector<int> v(10101);

int main(int argc, char* argv[]) {
    //fio;

    int k, n;

    cin >> k >> n;

    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }

    ll front = 0;
    ll back = (ll)INT_MAX+1;
    int before_mid = 0;
    
    int result_mid;


    
    while(true) {
        if(front == back) {
            break;
        }
        ll mid = (front + back) / 2;
        if(before_mid == mid) {
            cout << mid << "\n";
            break;
        }
        before_mid = mid;
        ll result = 0;
        for(int i = 0; i < k; i++) {
            result += (int)(v[i] / mid);
        }

        //cout << front << " " << back << " - " << mid << "\n";

        if(result == n) {
            //cout << mid << "\n";
            front = mid;
            continue;
            //result_mid = mid;
            //break;
        }

        if(result > n) {
            front = mid;
        }
        else {
            back = mid;
        }
    }

    

    return 0;
}
