#define true 1
#define false 0
typedef long long ll;
typedef int bool;

#include <stdio.h>

int main() {
    int n;

    while(true){
        scanf("%d", &n);

        if(n == -1){
            break;
        }

        int sum = 0;
        int count = 0;

        for(int i = 1; i <= n / 2; i++){
            if(!(n%i)) {
                sum += i;
                count++;
            }
        }

        if(sum != n){
            printf("%d is NOT perfect.\n", n);
            continue;
        }

        int print_count = 0;

        printf("%d = ", n);
        for(int i = 1; i <= n/2; i++){
            if(!(n%i)) {
                printf("%d", i);
                print_count++;

                if(print_count != count){
                    printf(" + ");
                    
                }

                else{
                    break;
                }
            }
        }

        printf("\n");

    }
    return 0;
}