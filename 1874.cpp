#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    stack<int> s;
    vector<char> v;

    int count = 1;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;

        while(count <= t){
            v.push_back('+');
            s.push(count);
            count++;
        }

        if(s.top() == t){
            v.push_back('-');
            s.pop();
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}