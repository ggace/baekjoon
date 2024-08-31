#include <stdio.h>
#include <string.h>

void go() {
    char str1[1000];
    char str2[1000];

    int str1_alphabet_count[26] = {0, };
    int str2_alphabet_count[26] = {0, };
    
    scanf("%s %s", str1, str2);
    if(strlen(str1) != strlen(str2)){
        printf("Impossible\n");
        return;
    }

    for(int i = 0; i < strlen(str1); i++){
        str1_alphabet_count[str1[i] - 'a']++;
        str2_alphabet_count[str2[i] - 'a']++;
    }

    for(int i = 0; i < 26; i ++){
        if(str1_alphabet_count[i] != str2_alphabet_count[i]){
            printf("Impossible\n");
            return;
        }
    }

    printf("Possible\n");
}

int main() {
    int n;

    scanf("%d", &n);

    while(n--){
        go();
    }
}