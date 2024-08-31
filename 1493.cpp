#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(ll i1, ll i2) {
    return i1 > i2;
}

vector<pair<ll, ll>> v;

int main(){
    fio;

    ll count = 0;

    ll length, width, height;
    ll n;
    ll a = 1, b;

    ll length_used = 0, width_used = 0, height_used = 0;

    cin >> length >> width >> height;
    cin >> n;

    for(ll i = 0; i < n; i++) {
        ll t;

        cin >> t >> b;

        v.push_back({a, b});

        a *= 2;
    }

    ll extra_to_add = 0;

    ll full_volume = length * width * height;

    for(ll i = n-1; i >= 0; i--) {

        ll current_digit = v[i].first;
        ll current_count = v[i].second;
        ll before_length_count = length_used / current_digit, before_width_count = width_used / current_digit, before_height_count = height_used / current_digit;
        ll current_length_count = length / current_digit, current_width_count = width / current_digit, current_height_count = height / current_digit;

        ll expected_to_add_count = current_length_count * current_width_count * current_height_count - before_length_count * before_width_count * before_height_count + extra_to_add;
        extra_to_add = 0;

        if(current_count < expected_to_add_count) {
            // todo write code to change digit;
            extra_to_add = 8* (expected_to_add_count - current_count);
            expected_to_add_count = current_count;
        }

        
        count += expected_to_add_count;
        full_volume -= expected_to_add_count * current_digit * current_digit * current_digit;

        length_used += current_digit * (current_length_count - before_length_count);
        width_used += current_digit * (current_width_count - before_width_count);
        height_used += current_digit * (current_height_count - before_height_count);



    }

    if(full_volume) {
        cout << "-1\n";
    }
    else{
        cout << count << "\n";

    }

    

    return 0;
}
