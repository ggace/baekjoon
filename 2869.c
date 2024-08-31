#define true 1;
#define false 0;
typedef long long ll;
typedef int bool;

#include <stdio.h>
#include <math.h>

int main() {
    
    int A, B, V;

    scanf("%d %d %d", &A, &B, &V);

    printf("%.0lf", ceil((V-A) / (double)(A-B)) + 1);

    return 0;
}