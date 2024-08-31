#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int main() {

    int result_x = 0, result_y = 0;

    int x, y;

    for(int i = 0; i < 3; i++){
        scanf("%d %d", &x, &y);
        result_x ^= x;
        result_y ^= y;
    }

    printf("%d %d\n", result_x, result_y);
    
    return 0;
}