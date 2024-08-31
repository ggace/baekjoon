#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int main() {

    int max_x = -10000;
    int max_y = -10000;
    int min_x = 10000;
    int min_y = 10000;

    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int x, y;

        scanf("%d %d", &x, &y);

        if(max_x < x){
            max_x = x;
        }
        if(max_y < y){
            max_y = y;
        }

        if(min_x > x){
            min_x = x;
        }
        if(min_y > y){
            min_y = y;
        }
    }

    printf("%d\n", (max_x - min_x) * (max_y - min_y));
    
    return 0;
}