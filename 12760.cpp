#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<vector<int>> v;
vector<pair<int, int>> result;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    //fio;

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        result.push_back({0, i});
        vector<int> tmp_v;
        for(int j = 0; j < m; j++) {
            int x;

            cin >> x;

            tmp_v.push_back(x);
        }

        sort(tmp_v.begin(), tmp_v.end(), reverse_compare);

        v.push_back(tmp_v);
    }

    for(int i = 0; i < m; i++) {
        vector<pair<int, int>> tmp_v;
        for(int j = 0; j < n; j++) {
            tmp_v.push_back({v[j][i], j});
        }

        sort(tmp_v.begin(), tmp_v.end(), compare);

        int current_value = tmp_v[0].first;
        result[tmp_v[0].second].first++;
        for(int j = 1; j < n; j++) {
            if(current_value == tmp_v[j].first) {
                result[tmp_v[j].second].first++;
            }
            else{
                break;
            }
        }
    }

    cout << "=========================================\n";

    sort(result.begin(), result.end(), compare);

    int current_value = result[0].first;
    for(int j = 0; j < n; j++) {

        //cout << result[j].first << " " << result[j].second << "\n";
        if(current_value == result[j].first) {
            cout << result[j].second+1 << " ";
        }
        else{
            break;
        }
    }

    cout << "\n";

    return 0;
}


/*
5 4 3
3 4 5
3 5 4
3 4 4
4 5 3
*/