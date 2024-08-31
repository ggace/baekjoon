#define true 1;
#define false 0;
typedef long long ll;
typedef int bool;

#include <math.h>

#include <stdio.h>

int main() {

    int x;

    scanf("%d", &x);

    if(x == 1){
        printf("1\n");
        return 0;
    }

    printf("%.0f\n", ceil(sqrt(x / 3. - 1 / 12.) - 1 / 2.) + 1);
       
    return 0;
}