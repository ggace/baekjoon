#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>
#include <stdlib.h>

int main() {

    int x,y,w,h;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    int min = abs(x);

    if(min > abs(y)){
        min = abs(y);
    }
    if(min > abs(w-x)){
        min = abs(w-x);
    }
    if(min > abs(h-y)) {
        min = abs(h-y);
    }

    printf("%d\n", min);
    
    
    return 0;
}