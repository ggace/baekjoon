#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(ll i1, ll i2) {
    return i1 > i2;
}

ll get_square(ll n) {
    ll result = 0;

    for(ll i = 0; i < 10; i++) {
        ll t = (n%10);
        result += t * t;
        n /= 10;
    }

    return result;
}

void solution(ll a, ll b) {
    ll result = 0;
    ll original_a = a, original_b =  b;

    map<ll, ll> m;
    
    for(ll i = 1; ; i++) {
        

        
        if(m[a] > 0 && m[b] < 0) {
            break;
        }
        if(m[a] < 0) {
            result = i - m[a];
            break;
        }
        
        if(!m[a])
            m[a] = i;

        if(m[b] > 0) {
            result = i + m[b];
            break;
        }
        
        if(!m[b])
            m[b] = -i;

        cout << a << " " << m[a] << ", " << b << " " << m[b]<<'\n';

        
        a = get_square(a);
        b = get_square(b);

    }


RESULT:
    cout << original_a << " " <<  original_b << " " << result << "\n";
    cout << "=====================================================\n";
    
}

int main(){
    fio;


    ll a, b;

    while(true) {
        cin >> a >> b;
        if(!(a | b)) {
            break;
        }

        solution(a, b);
    }

    return 0;
}
