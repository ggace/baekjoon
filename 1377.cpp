#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {

    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;

}

int main(int argc, char* argv[]) {
    fio;

    int n;

    cin >> n;

    for(int i = 0; i <n; i++) {
        int a;
        cin >> a;

        v.push_back({a, i});
    }

    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        //cout << v[i].first << " " << v[i].second << "\n";
    }

    int before_index = -1;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int current_index = v[i].second;
        
        if(before_index < current_index) {
            before_index = current_index;
            count++;
            //cout << current_index << " ";
        }
    }

    cout << n+ 1 - count << "\n";



    return 0;
}
