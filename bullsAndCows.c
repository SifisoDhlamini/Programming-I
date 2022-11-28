#include<stdio.h>
#include<string.h>

int main(void){
    char secret[100];
    char guess[100];
    int bulls = 0;
    int cows = 0;

    scanf("%s", &secret);
    scanf("%s", &guess);

    int lengthS = strlen(secret);
    int lengthG = strlen(guess);

    for(int i = 0; i < lengthG; i++){
        for(int j = 0; j < lengthS; j++){
            if(guess[i] == secret[j]){
                if(i == j){
                    bulls++;
                } else {
                    cows++;
                }
            }
        }
    }

    printf("%d %d", bulls, cows);
}
