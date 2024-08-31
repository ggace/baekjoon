#define FastIO() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;



using namespace std;

bool compare(string a, string b){
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }

    int a_number = 0;
    int b_number = 0;

    for(int i = 0; i < a.length(); i++) {
        if('0' <= a[i] && a[i] <= '9'){
            a_number += a[i] - '0';
        }
        if('0' <= b[i] && b[i] <= '9'){
            b_number += b[i] - '0';
        }
    }
    if(a_number != b_number) {
        return a_number < b_number;
    }

    return a < b;
}

int main() {

    FastIO();

    int n; 
    vector<string> arr;

    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        arr.push_back(str);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}