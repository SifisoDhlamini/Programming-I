#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>

int main(){
    bool isApalindrome = true;
    int i, j, half, full;
    char str[100];
    scanf("%s", str);
    full = strlen(str);
    half = strlen(str) / 2;

        for (i = 0; i <= half; i++){
            if (full % 2 == 0){
                if (tolower(str[i]) != tolower(str[(full - i) - 1])){
                   isApalindrome = false;
                    break;
                }

            } else {
                if (tolower(str[i]) != tolower(str[(half * 2 - i)])){
                    isApalindrome = false;
                    break;
                }


            }
        }

        if (isApalindrome){
            printf("%s is a palindrome.", str);
        } else {
            printf("%s is not a palindrome.", str);
        }

        return 0;
}
