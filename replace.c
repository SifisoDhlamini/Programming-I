#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char *replace(char *source, char *pattern, char *replacement)
{
    char *s = source;
    char *p = pattern;
    char *r = replacement;

    int countP = 0;
    int countR = 0;
    int countS = 0;

    while(*r != '\0'){
        countR++;
        r++;
    }
    //printf("countR = %d\n", countR);
    r = replacement;

    while(*p != '\0'){
        countP++;
        p++;
    }
    //printf("countP = %d\n", countP);
    p = pattern;

    while(*s != '\0'){
        countS++;
        s++;
    }
    //printf("countS = %d\n", countS);
    s = source;

    int match = 0;
    int index;
    int diff = countR - countP;
    countS+=diff;
    for(int i = 0; i < countS && !(match); i++){
        if(*(s + i) == *p){
            for (int j = 0; j < countP; j++){
//                printf("s[i + j] = %c\n", s[i + j]);
//                printf("*(p + j) = %c\n", *(p + j));
                if(j == (countP - 1) && s[i + j] == *(p + j)){
                    match = 1;
                } else if(s[i + j] != *(p + j)){
                    break;
                }
            }
            if(match == 1){
                 char remaining[countS - i];
                //continue from here and save copy of remaining characters*******************
                for(int rem = 0; rem < countS - i; rem++){
                    remaining[rem] = *(s + i + rem + countP);
                    //printf("%c", remaining[rem]);
                }
                //printf("\n");
                for(int k = 0; k < countR; k++){
//                    printf("s[i + k] = %c\n", s[i + k]);
//                    printf("*(r + k) = %c\n", *(r + k));
                    s[i + k] = *(r + k);
                }
                //After replacing, replenish with remainder[] characters starting from i + countR
                for (int rem = 0; rem <= countS - (i + countR); rem++){
                    *(s + i + countR + rem) = remaining[rem];
                }
            }
        }
    }

    return source;
}

char *replaceAll(char *source, char *pattern, char *replacement)
{
    char *s = source;
    char *p = pattern;
    char *r = replacement;

    int countP = 0;
    int countR = 0;
    int countS = 0;

    while(*r != '\0'){
        countR++;
        r++;
    }
    //printf("countR = %d\n", countR);
    r = replacement;

    while(*p != '\0'){
        countP++;
        p++;
    }
    //printf("countP = %d\n", countP);
    p = pattern;

    while(*s != '\0'){
        countS++;
        s++;
    }
    //printf("countS = %d\n", countS);
    s = source;

    int diff = countR - countP;
    int match = 0;
    int index;
    for(int i = 0; i < countS; i++){
        if(*(s + i) == *p){
            for (int j = 0; j < countP; j++){
//                printf("s[i + j] = %c\n", s[i + j]);
//                printf("*(p + j) = %c\n", *(p + j));
                if(j == (countP - 1) && s[i + j] == *(p + j)){
                    match = 1;
                } else if(s[i + j] != *(p + j)){
                    break;
                }
            }
            if(match == 1){
                countS+=diff;
                char remaining[countS - i];
                //continue from here and save copy of remaining characters******************
                for (int rem = 0; rem <= countS - i; rem++){
                    remaining[rem] = *(s + i + rem + countP);
                    //printf("%c", remaining[rem]);
                }
                //printf("\n");
                for(int k = 0; k < countR; k++){
//                    printf("s[i + k] = %c\n", s[i + k]);
//                    printf("*(r + k) = %c\n", *(r + k));
                    s[i + k] = *(r + k);
                }
                //After replacing, replenish with remainder[] characters starting from i + countR
                for (int rem = 0; rem <= countS - i; rem++){
                    *(s + i + countR + rem) = remaining[rem];
                }
            }
        }
        match = 0;
    }

    return source;
}

/*
int main(){
    char source[] = "lucolo Dhlamini lucoloini";
    char pattern[] = "luc";
    char replacement[] = "LUXX";
    char replacement2[] = "EA";
    char pattern2[] = "ini";

    replace(source, pattern, replacement);
    puts(source);
    replaceAll(source, pattern2, replacement2);
    puts(source);

    return 0;
}*/
