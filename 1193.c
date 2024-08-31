#include <stdio.h>
#include <math.h>

void go(int x){

    int first, second;

    int n = ceil((-1 + sqrt(1 + 8 * x)) / 2)-1;

    int sum = n * (n + 1) / 2;

    if(n & 1){
        first = x - sum;;
        second = n+2 - first;
    }
    else {
        second = x - sum;
        first = n + 2 - second;
    }
    printf("%d/%d\n", first, second);
}

int main(){

    int input;
    
    scanf("%d", &input);

    go(input);
    
    return 0;
}