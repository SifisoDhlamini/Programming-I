#include<stdio.h>
#include<stdlib.h>

char * mystrcat(char *dest, char *src);
char * mystrncat(char *dest, char *src, int n);

int main(void){
    char dest[100] = "abcd";
    char dest2[100] = "xxxx";
    char src[] = "efghijklmn";

    mystrncat(dest2, src, 5);
    mystrcat(dest, src);

    puts(dest2);
	puts(dest);


    return 0;
}

char * mystrcat(char *dest, char *src){
    char *d = dest;
    char *s = src;

    while (*d != '\0'){
        d++;
    }

    while(*s != '\0'){
        *d = *s;
        s++;
        d++;
    }

    *d = '\0';

    return dest;
}

char * mystrncat(char *dest, char *src, int n){
    char *p = dest;

    while (*p != '\0'){
        p++;
    }

    char *s = src;
    int count = 0;

    while(*s != '\0' && count < n){
        *p = *s;
        p++;
        s++;
        count++;
    }

    *p = '\0';

    return dest;
}




