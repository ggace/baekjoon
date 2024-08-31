/*
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<int> v;

int main(){
    fio;

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        v.push_back(tmp);

        if(v.size() > k) {
            v.erase(v.begin());
        }

        cout << *min_element(v.begin(), v.end()) << " ";
    }

    cout << "\n";

    return 0;   
}*/
/*

#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int arr[10000000];

int main(){
    fio;

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < 10000000; i++) {
        arr[i] = 2000000000;
    }

    for(int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;

        v.push_back({tmp, i});
    }

    sort(v.begin(), v.end(), compare);

    int count = 0;

    for(int i = 0; i < n; i++) {
        int index = v[i].second;
        int value = v[i].first;
        for(int j = 0; j < k; j++) {
            if(arr[index+j] != 2000000000) {
                continue;
            }

            if(index+j >= n) {
                continue;
            }
            arr[index+j] = value;
            count++;

            if(count == n) {
                cout << i << " " << j << "\n";
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;   
}
*/


#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

vector<int> v;

int main(){
    fio;

    int n, k;

    cin >> n >> k;

    int cur_min_index = -1;
    int cur_min = 0x7fffffff;

    for(int i = 0; i < n; i++){
        
        int tmp;
        cin >> tmp;

        if(cur_min > tmp) {
            cur_min = tmp;
            cur_min_index = i;
        }
        if(v.size() > k) {
            
            cout << "\n";
            
            v.erase(v.begin());
            cur_min_index = min_element(v.begin(), v.end()) - v.begin();
            cur_min = v[cur_min_index];
        }

        v.push_back(tmp);

        if(v.size() > k) {
            v.erase(v.begin());
        }

        for(int j = 0; j < k; j++) {
            cout << v[j] << " ";
        }

        cout << "| " << cur_min << ", " << cur_min_index;
        cout << "\n";

        //cout << cur_min << " ";
    }

    cout << "\n";

    return 0;   
}