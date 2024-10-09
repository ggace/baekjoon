#include <stdio.h>

typedef struct _pair {
    int first;
    int second;
} pair;

int main() {
    long long a = 0x0000000200000001;
    printf("%lld\n", a);
    printf("%d\n", (int)a);
    printf("%d\n", (int)(a >> 32));

    pair p = {2,1};

    printf("%d\n", p.first);
    printf("%d\n", p.second);
    return 0;
}