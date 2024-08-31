#include <stdio.h>

int main() {
    int paper[100][100] = {0};

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                paper[y+j][x+k] = 1;
            }
        }
    }

    int sum = 0;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            sum += paper[i][j];
        }
    }

    printf("%d", sum);
}