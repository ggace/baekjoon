#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio;

    char king_pos[3];
    char rock_pos[3];

    cin >> king_pos >> rock_pos;


    king_pos[0] -= 'A'-1;
    king_pos[1] -= '1'-1;
    rock_pos[0] -= 'A'-1;
    rock_pos[1] -= '1'-1;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string cmd;

        cin >> cmd;
        int x_add = 0;
        int y_add = 0;

        if(cmd.find('R') != string::npos) {
            if(king_pos[0] + 1 > 8){
                continue;
            }
            x_add = 1;
        }
        else if(cmd.find("L") != string::npos) {
            if(king_pos[0] - 1 < 1){
                continue;
            }
            x_add = -1;
        }
        if(cmd.find('B') != string::npos) {
            if(king_pos[1] - 1 < 1) {
                continue;
            }
            y_add = -1;
        }
        else if(cmd.find('T') != string::npos) {
            if(king_pos[1] + 1 > 8) {
                continue;
            }
            y_add = 1;
        }

        

        king_pos[0] += x_add;
        king_pos[1] += y_add;
        if(rock_pos[0] == king_pos[0] && king_pos[1] == rock_pos[1]) {
            if(rock_pos[0] + x_add > 8 || rock_pos[0] + x_add < 1 || rock_pos[1] + y_add > 8 || rock_pos[1] + y_add < 1) {
                king_pos[0] -= x_add;
                king_pos[1] -= y_add;
                continue;
            }
            rock_pos[0] += x_add;
            rock_pos[1] += y_add;
        }
    }

    cout << (char)(king_pos[0]-1 + 'A') << (char)(king_pos[1]-1 + '1') << "\n";
    cout << (char)(rock_pos[0]-1 + 'A') << (char)(rock_pos[1]-1 + '1') << "\n";

    return 0;
}
