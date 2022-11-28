#include<stdio.h>
#include<string.h>

int main(void){
    char words[100][100];
    int numWords;

    scanf("%d", &numWords);

    for(int i = 0; i < numWords; i++){
        scanf(" %s", words[i]);
    }

    //sort(words, numWords);
    char temp[100];
    for(int i = 0; i < numWords - 1; i++){
        for(int j = i + 1; j < numWords; j++){
            if(strcmp(words[i], words[j]) > 0){
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }


    for(int i = 0; i < numWords; i++){
        printf("%s\n", words[i]);
    }

    return 0;
}


