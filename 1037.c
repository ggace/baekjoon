#include <stdio.h>

int main() {
    int n;
    int max = 0;
    int min = 1000001;
    int input;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &input);

        if(min > input){
            min = input;
        }
        if(max < input){
            max = input;
        }
    }

    printf("%d", min * max);

    return 0;
}