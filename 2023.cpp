#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

queue<int> q;

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(!(n%i)){
            return false;
        }
    }

    return true;
}

int main(){
    fio;

    int n;

    cin >> n;

    int max_digit = 1;
    int digit = 1;

    for(int i = 0; i < n; i++) {
        max_digit *= 10;
        if(i != 0) {
            digit *= 10;
        }
    }

    //cout << max_digit << " << " << digit << "\n";

    //cout << 73939133 / 10000000 << "\n";

    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    while(true) {

        if(q.empty()) {
            //cout << "break1\n";
            break;
        }
        int t = q.front();
        //cout << t << "\n";
        q.pop();
        
        if(t / max_digit != 0){
            //cout << "break2\n";
            break;
        }
        if(t / digit != 0) {
            cout << t << "\n";
        }

        for(int i = 1; i < 10; i+=2) {
            int next = t * 10 + i;

            if(is_prime(next)) {
                q.push(next);
            }
        }
        
    }

    return 0;
}
