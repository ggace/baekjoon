#define true 1
#define false 0
typedef long long ll;

#include <stdio.h>

const ll MAX = 0x7fffffffffffffff;
const ll MIN = ~MAX;

int main() {
    int count = 0;
    ll n;
    int b;

    int arr[45] = {0, };

    scanf("%lld %d", &n, &b);

    for(int i = 0; true; i++){
        arr[i] = n % b;
        if(n / b < b){
            arr[i+1] = n / b;
            break;
        }

        n /= b;

        count++;
    }

    for(int i = count+1; i >= 0; i-- ){
        int curret_number = arr[i];
        if(i == count + 1 && curret_number == 0){
            continue;
        }
        
        if(10 <= curret_number ){
            printf("%c", curret_number - 10 + 'A');
        }
        else{
            printf("%d", curret_number);
        }
    }
   return 0;
}