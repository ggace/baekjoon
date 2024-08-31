#define fio() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int main(){
    fio();

    int n;

    cin >> n;

    while(n--) {
        string str;

        int wrong = 0;
        int uncount_char = 0;

        cin >> str;

        int str_length = str.length();

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '@'){
                str[i] = 'a';
                wrong++;
            }
            else if(str[i] == '['){
                str[i] = 'c';
                wrong++;
            }

            else if(str[i] == '!'){
                str[i] = 'i';
                wrong++;
            }
            else if(str[i] == ';'){
                str[i] = 'j';
                wrong++;
            }
            else if(str[i] == '^'){
                str[i] = 'n';
                wrong++;
            }
            else if(str[i] == '0'){
                str[i] = 'o';
                wrong++;
            }
            else if(str[i] == '7'){
                str[i] = 't';
                wrong++;
            }
            else if(str[i] == '\\'){
                if(str[i+1] == '\\' && str[i+2] == '\''){
                    str[i] = 'w';
                    str[i+1] = '_';
                    str[i+2] = '_';
                    wrong++;
                    i += 2;
                    uncount_char+= 2;
                }
                else if(str[i+1] == '\''){
                    str[i] = 'v';
                    str[i+1] = '_';
                    wrong++;
                    i += 1;
                    uncount_char+= 1;
                }
            }
        }

        if(wrong >= (str.length() - uncount_char) / 2.0){
            cout << "I don't understand\n";
            continue;
        }

        for(int i = 0; i < str.length(); i++) {
            if(str[i] != '_')
                cout <<str[i];
        }
        cout << "\n";
    }

    return 0;
}