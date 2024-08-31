#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int arr[4];
vector<int> original_v;
vector<int> sorted_v;
int n;
ll minimum_result = LONG_LONG_MAX;

void make_sorted_v(int a, int b, int c) {
    sorted_v.clear();
    for(int i = 0; i < arr[a]; i++) {
        sorted_v.push_back(a);
    }
    for(int i = 0; i < arr[b]; i++) {
        sorted_v.push_back(b);
    }
    for(int i = 0; i < arr[c]; i++) {
        sorted_v.push_back(c);
    }
}

void compare_v() {
    ll result = 0;
    ll incorrect_count = 0;
    vector<vector<ll>> t;
    for(int i = 0; i <= 3; i++) {
        t.push_back({0,0,0,0});
    }
    for(int i = 0; i < n; i++) {
        int p = original_v[i];
        int q = sorted_v[i];
        t[p^q][q]++;
        if(p ^ q) {
            
            incorrect_count++;
        }
    }

    
    for(int i = 1; i <= 3; i++) {
        ll before_count = 0;
        bool trigger = false;
        for(int j = 1; j <= 3; j++) {
            
            if(t[i][j] != 0) {
                if(before_count != 0) {
                    trigger = true;
                    before_count = min(before_count, t[i][j]);
                    break;
                }
                else {
                    before_count = t[i][j];
                }
            }
        }
        if(trigger){
            result += before_count;
            incorrect_count -= before_count * 2;
        }
    }
    if(incorrect_count > 1) {
        result += incorrect_count/3*2;
    }

    if(result < minimum_result) {
        minimum_result = result;
    }
    


}

int main(int argc, char* argv[]) {
    fio;
    

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        arr[a]++;

        original_v.push_back(a);
    }

    make_sorted_v(1,2,3);
    compare_v();
    make_sorted_v(1,3,2);
    compare_v();
    make_sorted_v(2,1,3);
    compare_v();
    make_sorted_v(2,3,1);
    compare_v();
    make_sorted_v(3,1,2);
    compare_v();
    make_sorted_v(3,2,1);
    compare_v();


    cout << minimum_result << "\n";

    
    

    return 0;
}
