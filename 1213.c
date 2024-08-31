#include <stdio.h>
#include <string.h>

int main(){

    char alphabet['Z' - 'A' + 1] = {0, };

    char str[50];

    char odd_count = 0;
    int odd_index;

    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++){
        alphabet[str[i] - 'A'] ++;
    }

    for( int i = 0; i < 'Z' - 'A' + 1; i++){
        odd_count += alphabet[i] % 2;
        if(alphabet[i] % 2){
            odd_index = i;
        }
    }

    if(!(odd_count == 1 || odd_count == 0)){
        printf("I'm Sorry Hansoo\n");
        return 0;
    }

    for(int i = 0; i < 'Z' - 'A' + 1; i++){
        for(int j = 0; j < alphabet[i] / 2; j++){
            printf("%c", i + 'A');
        }
    }
    
    if(odd_count == 1){
        printf("%c", odd_index + 'A');
    }

    for(int i = 0; i < 'Z' - 'A' + 1; i++){
        for(int j = 0; j < alphabet['Z' - 'A' - i] / 2; j++){
            printf("%c", 'Z' - i);
        }
    }
    printf("\n");

    return 0;
}