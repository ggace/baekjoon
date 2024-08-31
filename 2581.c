#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>



int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    int sum = 0;
    int start_prime = -1;
    int add_value;

    for(int i = a; i <= b; i++){
        if(i <= 1){
            add_value = 0;
            continue;
        }
        add_value = i; 
        for(int j = 2; j <= i/2; j++){
            if(i % j == 0){
                add_value = 0;
                break;
            }
        }
        if(start_prime == -1 && add_value != 0){
            start_prime = add_value;
        }
        sum += add_value;
    }
    if(sum == 0){
        printf("-1");
        return 0;
    }
    printf("%d\n%d\n", sum, start_prime);
    return 0;
}