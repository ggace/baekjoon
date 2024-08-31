#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#define rest 1000000007

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

deque<int> d;
deque<int> times;
vector<int> v;

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        v.push_back(value);
    }

    if(n <= 1) {
        cout << "0\n";
        return 0;
    }
    sort(v.begin(), v.end());
    
    ll diff_sum = 0;
    ll times_sum = 0;

    int bin = 1;
    
    for(int i= 1; i < n; i++) {
        int diff = (v[i]-v[i-1])%rest;
        d.push_back(diff);
        diff_sum += diff;

        times.push_back(bin);
        times_sum += bin;
        bin *= 2;
        bin %= rest;

        diff_sum %= rest;
        times_sum %= rest;
    }

    ll result = 0;

    while(true) {
        //cout << diff_sum << " " << times_sum << "\n";
        result += ((diff_sum % rest) * (times_sum%rest) ) % rest;
        result %= rest;

        int d_front = d.front();
        int d_back = d.back();
        
        diff_sum -= d_front + d_back;
        diff_sum %= rest;
        if(diff_sum < 0) {
            diff_sum += rest;
        }

        int time_front = times.front();
        int time_back = times.back();
        
        times_sum -= time_front + time_back;
        times_sum %= rest;
        if(times_sum < 0) {
            times_sum += rest;
        }

        d.pop_front();
        times.pop_front();
        if(d.size() != 0) {
            d.pop_back();
            times.pop_back();
        }

        if(d.empty()) {
            break;
        }
    }

    cout << result << "\n";

    

    return 0;
}
