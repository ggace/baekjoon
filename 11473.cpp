#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

ll goal = 3107338;
int K;
bool is_eng(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

void find_str(ll goal, string result) {
    char current_char = goal % 31;
    ll next_goal = (goal - current_char) / 31;

    current_char += 31*2;
    if(is_eng(current_char)) {
        //cout << result << "\n";
        if(next_goal-2 <= 'z') {
            if(is_eng(next_goal-2)) {
                printf("%c%c%s\n", (char)(next_goal-2), current_char, result.c_str());
                K--;
                if(!K) {
                    exit(0);
                }
            }
            goto next_check;
        }
        
        find_str(next_goal-2, current_char + result);
    }
next_check:
    current_char += 31;
    if(is_eng(current_char)) {
        //cout << result << "\n";
        if(next_goal-3 <= 'z') {
            if(is_eng(next_goal-3)) {
                printf("%c%c%s\n", (char)(next_goal-3), current_char, result.c_str());
                K--;
                if(!K) {
                    exit(0);
                }
            }
            return;
        }
        
        find_str(next_goal-3, current_char + result);
    }
}

int main(int argc, char* argv[]) {
    fio;

    
    cin >> K;

    while(K){
        find_str(goal, "");
        goal += 4294967296;
    }

    return 0;
}
