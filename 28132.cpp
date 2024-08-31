#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

map<pair<ll, ll>, ll> m;

ll result = 0;

int main(int argc, char* argv[]) {
    fio;
    int n;
    cin >> n;
    int n_for_zero = n-1;
    
    for(int i = 0; i < n; i++) {
        ll x, y;
        pair<ll, ll> p;
        cin >> x >> y;

        ll g = gcd(x, y);
        
        if(x == 0 && y == 0) {
            
            result += n_for_zero*2;
            //cout << n_for_zero << ": " << result << "\n";
            
            --n_for_zero;
            continue;
        }
        //cout << x << ", " << y << ": ";
        if(x == 0) {
            g = y;
        }
        if(x < 0) {
            g = -g;
        }
        
        p = {x/g, y/g};

        //cout << p.first << ", " << p.second << "\n";
        
        
        
        auto ele = m.find(p);
        if(ele == m.end()) {
            m.insert({p, 1});
        }
        else {
            (ele->second)++;
        }

    }

    for(auto i = m.begin(); i != m.end(); i++) {
        auto [x1, y1] = i->first;
        ll count1 = i->second;
        //cout << x1 << ", " << y1 << " >> ";
        
        int t = 1;
        if(y1 < 0) {
            t = -1;
        }

        x1 *= t;
        y1 *= t;

        

        if(y1 != 0) {
            x1 = -x1;
        }

        //cout << y1 << ", " << x1 << "\n";

        
        
        auto ele = m.find({y1, x1});

        
        if(ele != m.end()) {
            //cout << ele->second << " * " << count1 << "\n";
            result += ele->second * count1;
        }
    }
    //cout << zero_count << "\n";
    cout << (ll)(result/2) << "\n";

    return 0;
}