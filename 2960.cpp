#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;

#include <bits/stdc++.h>

using namespace std;

bool reverse_compare(int i1, int i2) {
    return i1 > i2;
}

int visited[1000] = {0};

int main(){
    //fio;

    int n, m;

    cin >> n >> m;

    int count = 0;

    int index = 0;

    int term = 2;

    while(true) {
        //cout << index << "\n";
        if(!visited[index]){
            //cout << index << "에서 count++\n";
            visited[index] = 1;
            count++;
            if(count == m) {
                cout << index+2 << "\n";
                break;
            }
        }
        index += term;

        if(index >= n-1) {
            //cout << index << "에서 change to ";
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    index = i;
                    term = index+2;
                    break;
                }
            }

            //cout << index << "\n";
        }


    }

    

    return 0;
}
