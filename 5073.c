#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>

int main() {

    int a;
    int b;
    int c;

    while(true){
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0 &&b==0 && c==0){
            break;
        }

        if(a >= b+c || b >= a+c || c >= a+b){
            printf("Invalid\n");
        }

        else if(a == b && b == c && c == a){
            printf("Equilateral\n");
        }
        else if(a != b && b != c && c != a){
            printf("Scalene\n");
        }
        else{
            printf("Isosceles\n");
        }
    }

    
    
    
    return 0;
}