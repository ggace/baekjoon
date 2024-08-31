#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>
#include <stdlib.h>

int arr[3000][2];
ll count = 0;
int n;
int K;

void go(int index, int before_value) {
    for(int i = arr[index][0]; i <= arr[index][1]; i++) {
        if(before_value == 0 || abs(before_value - i) <= K) {
            if(index >= n-1) {
                
                count++;
                count = count % 1000000007;
                continue;
            }
            go(index+1, i);

            
        }
        else {
            if(i > before_value) {
                break;
            }
            continue;
        }
    }
}

int main() {
    scanf("%d %d", &n, &K);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    go(0,0);

    printf("%lld\n", count);
    
    return 0;
}