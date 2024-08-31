#include <iostream>

using namespace std;

int main() {
    char strs[5][15];
    int state[5] = {0,0,0,0,0};

    for(int i = 0; i < 5; i++){
        scanf("%s", strs[i]);
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(state[j] == -1){
                continue;
            }
            cout << strs[j][i];
            state[j]++;
            if(strs[j][state[j]] == 0){
                state[j] = -1;
            }
        }
    }


}