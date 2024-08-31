#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}


int main(){
    fio;

    int n;
    int w[1000];
    int m;
    int l[1000];
    int k;
    int result = 0;

    cin >> n;

    for(int i =0; i < n; i++) {
        cin >> w[i];
    }

    cin >> m;
    
    for(int i =0; i < m; i++) {
        cin >> l[i];
    }

    cin >> k;

    int w_index = 0, l_index = 0;

    while(true) {
        if(w_index == n && l_index == m) {
            break;
        }

        //cout << result << "\n" << w_index << ", " << l_index << "\n\n";
        if(w_index == n) {
            if(result % k == 0) {
                result -= l[l_index];
            }
            else if(result <= 0) {
                result -= l[l_index];
            }
            else {
                int minus = min({l[l_index], result % k});
                result -= minus;
            }
            
            l_index++;
            continue;
        }
        if(l_index == m) {
            result += w[w_index];
            w_index++;
            continue;
        }
        if(result == 0) {
            result += w[w_index];
            w_index++;
            continue;
        }
        int temp_result = result + w[w_index];
        
        if(result / k < temp_result / k) {
            result += w[w_index];
            w_index++;
            continue;
        }
        
        if(result % k == 0) {
            result -= l[l_index];
        }
        else if(result <= 0) {
            result -= l[l_index];
        }
        else {
            int minus = min({l[l_index], result % k});
            result -= minus;
        }
        l_index++;
        
        

        

    }

    cout << result << "\n";

    return 0;
}
