#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>
#include <math.h>

int result[10] = {0};

void go(int n, int digit){
    if(digit == 1){
        
        for(int i = 0; i <= n;i++){
            result[i]++;
        }
        return;
    }

    for(int i = 0; i <= n / digit; i++){
        if(i != 0 && i != n/digit){
            result[i] += digit;
        }

        else if(i == n / digit){
            result[i] += (n % digit+1);
        }
        if(i == n/digit){
            go(n % digit, digit/10);
        }
        else{
            go(9 * digit / 10, digit/10);
        }
        
        
    }
}

int main() {

    int n;

    scanf("%d", &n);


    int digit = 1;

    for(int i = 0; i < (int)log10(n); i++){
        digit *= 10;
    }

    printf("%d\n", digit);

    go(n, digit);

    result[0] --;
    for(int i = 0; i <= 9; i++){
        
        printf("%d ", result[i]);
    }

    printf("\n");
    
    return 0;
}