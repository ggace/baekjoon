
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<pair<int, int>> jewerly;
vector<int> bag;

int main(){
    fio;

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int m, v;

        cin >> m >> v;

        jewerly.push_back({m, v});
    }

    sort(jewerly.begin(), jewerly.end(), compare);

    int result = 0;

    for(int i = 0; i < k; i++) {
        int c;

        cin >> c;

        bag.push_back(c);
    }


    int index = 0;
    sort(bag.begin(), bag.end(), reverse_compare);
    for(int i = 0; i < bag.size(); i++){
        for(int j= index; j < jewerly.size();j++) {
            //cout << jewerly[j].first << "\n";
            if(jewerly[j].first <= bag[j]) {
                //cout << "end\n";
                result += jewerly[j].second;
                index = j;
                jewerly.erase(jewerly.begin() + j);
                break;;
            }
        }
    }
    

    cout << result << "\n";

    return 0;
}
