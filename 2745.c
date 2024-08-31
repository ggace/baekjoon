#define true 1;
#define false 0;
typedef long long ll;

#include <stdio.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

int main(){

    ll result = 0;
    int arr[45];
    int number;
    int count = 0;

    for(int i = 0; 1; i++){
        char c;
        scanf("%c", &c);
        if(c == 32){
            break;
        }
        if('A' <= c && c <= 'Z'){
            arr[i] = c - 'A' + 10;
        }
        else if('0' <= c && c <= '9') {
            arr[i] = c - '0';
        }
        count ++;
    }

    int times = 1;

    scanf("%d", &number);
    
    for(int i = count-1; i >= 0; i--){
        result += arr[i] * times;
        times *= number;
    }

    printf("%lld\n", result);
    return 0;
}