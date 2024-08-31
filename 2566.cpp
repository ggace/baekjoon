#include <iostream>

using namespace std;

int main() {
    int arr[9][9];

    int max = -1;
    int x, y;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];

            if(max < arr[i][j]){
                max = arr[i][j];
                y = i;
                x = j;
            }
        }
    }

    cout << max << "\n" << y+1 << " " << x+1;


}