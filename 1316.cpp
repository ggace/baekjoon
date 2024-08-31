/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1316                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skydream10 <boj.kr/u/skydream10>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1316                           #+#        #+#      #+#    */
/*   Solved: 2024/04/28 23:18:58 by skydream10    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#define FastIO() cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;

#include <iostream>
#include <vector>
#include <algorithm>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

using namespace std;

int go() {
    int alphabet[26] = {0, };
    string str;

    cin >> str;

    for(int j = 0; j < str.length(); j++){
        alphabet[str[j] - 'a']++;
    }

    char before_alphabet = str[0];
    alphabet[before_alphabet - 'a']--;

    for(int j = 1; j < str.length(); j++){

        alphabet[str[j] - 'a']--;

        
        if(before_alphabet != str[j]){
            if(alphabet[before_alphabet - 'a']){
                return 0;
            }
            
            before_alphabet = str[j];
        }
        
    }

    return 1;
}

int main(){

    int n;
    cin >> n;

    int count=0;

    for(int i = 0; i < n; i++){
        count += go();
    }

    cout << count << "\n";

    return 0;
}