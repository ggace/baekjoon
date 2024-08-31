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

    scanf("%d %d %d", &a, &b, &c);

    if(a == 60 && b == 60 && c == 60){
        printf("Equilateral\n");
    }
    else if(a + b+ c != 180){
        printf("Error\n");
    }
    else{
        if(a != b && b != c && c != a){
            printf("Scalene\n");
        }
        else{
            printf("Isosceles\n");
        }
    }
    
    return 0;
}