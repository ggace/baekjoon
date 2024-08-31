#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int arr[1000000] = {0};

int main() {
    int n, m;
    int a, b;
    

    scanf("%d", &n);

    scanf("%d", &m);

    while(m--) {
        scanf("%d %d", &a, &b);

        arr[a-1] += 1;
        arr[b-1] -= 1;        
    }

    int temp = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        
        if(temp == 0){
            count++;
        }
        temp += arr[i];
    }

    printf("%d\n", count);

    return 0;
}