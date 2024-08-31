#define true 1
#define false 0
typedef long long ll;
typedef int bool;

#include <stdio.h>

int main() {
    int n, m;
    int count = 0;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        if(!(n%i)) {
            count++;
        }
        if(count == m){
            printf("%d\n", i);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}