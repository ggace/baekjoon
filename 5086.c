#define true 1
#define false 0
typedef long long ll;
typedef int bool;

#include <stdio.h>

int main() {
    int a, b;


    while (true){
        scanf("%d %d", &a, &b);

        if(a == 0 && b == 0){
            break;
        }

        if(a % b == 0){
            printf("multiple\n");
        }
        else if(b % a == 0){
            printf("factor\n");
        }
        else{
            printf("neither\n");
        }
    }
    
    return 0;
}