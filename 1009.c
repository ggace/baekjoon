#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>



void solution() {
    int arr[1000] = {0};    
    int a, b;

    int n;
    
    scanf("%d %d", &a, &b);
    
    a = a % 10;

    if(a == 0) {
        printf("10\n");
        return;
    }

    arr[0] = a;
    int count = 1;

    for(int i = 1; ; i++) {
        
        n = (arr[i-1] * a) % 10;
        if(n == arr[0]){
            break;
        }

        arr[i] = n;
        count++;
    }
    if(count == 1) {
        printf("%d\n", arr[0]);
        return;
    }
    
    int index = b % count == 0? count-1 : b % count - 1;
    printf("%d\n", arr[index]);

}

int main() {
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        solution();
    }
    
    return 0;
}
