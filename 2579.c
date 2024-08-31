#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int n;

int arr[300];

int max = 0;

int count;

void go(int index, int continuous_count, int sum) {
    sum += arr[index];
    if(index == n-1) {
        
        if(sum > max) {
            max = sum;
        }
        return;
    }
    if(continuous_count >= 2) {
        return;
    }
    go(index+1, continuous_count+1, sum);
    if(index != n-2){
        go(index+2, 1, sum);
    }
    
}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    go(0,0,0);
    //go(1,0,0);

    printf("%d\n", max);
    
    return 0;
}