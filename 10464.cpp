#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

void solution() {
    int S, F;

    cin >> S >> F;

    int mult = 2;
    int max_mult = -1;
    int min_mult = -1;
    for(int i = 1; ; i++) {
        mult *= 2;
        if(max_mult == -1 && mult > F) {
            max_mult = mult/2;
        }
        if(min_mult == -1 && mult > S) {
            min_mult = mult;
        }

        if(max_mult != -1 && min_mult != -1) {
            break;
        }

    }

    cout << min_mult << " " << max_mult << "\n";

    int result = 0;

    if(min_mult > max_mult) {
        for(int i = S; i <= F; i++ ) {
            result ^= i;
        }
    }
    else {
        min_mult = min_mult - (int)((min_mult - S) / 4) * 4;
        max_mult = (int)((F - max_mult + 1) / 4) * 4 + max_mult;
        cout << min_mult << " " << max_mult << "\n";
        for(int i = S; i < min_mult; i++) {
            result ^= i;
        }
        for(int i = max_mult; i <= F; i++) {
            result ^= i;
        }
    }
    
    cout << result << "\n";
}

int main(){
    //fio;

    int t;

    cin >> t;

    while(t--) {
        solution();
    }

    return 0;
}
