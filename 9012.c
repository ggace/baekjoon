#define true 1;
#define false 0;
typedef long long ll;

#include <stdio.h>
#include <string.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

void go() {

    int sum = 0;

    char str[55];

    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++){
        sum += -(str[i] * 2 - 81);
        if(sum < 0){

            printf("NO\n");
            return;
        }
    }
    if(sum != 0){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    return;
}

int main() {

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        go();
    }
    return 0;
}