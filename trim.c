#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *trim(char *dest){

    char *ptr = dest;
    int counter = 0;

    while(*ptr == ' ' || *ptr == '\n' || *ptr == '\t'){
        ptr++;
    }

    char *end = ptr;

    while(* end != '\0'){
        counter++;
        *end++;
    }
    end--;
    while(*end == ' ' || *end == '\n' || *end == '\t'){
        counter--;
        end--;
    }
    *(end + 1) = '\0';
    counter++;
    //printf("%d\n", counter);
    for(int i = 0; i <= counter; i++){
        dest[i] = ptr[i];
    }
//    printf("%c\n", *end);
//    printf("%c\n", *ptr);
//    printf("%d\n", &end - &ptr);
//    printf("%p\n", &dest);
//    printf("%p\n", &ptr);
//    printf("%p\n", &end);

    return dest;
}

int main(void){
    char dest[100] = "    \n\n\t\t abcd    \n\n\t\t";

    trim(dest);
    printf("Dest is now = %d\n", strlen(dest));
	puts(dest);

    return 0;
}






