#include<stdio.h>
#include<string.h>

void printReverse(char string[], int length){
    if (length < 0){
        printf("\n");
    } else {
        printf("%c", string[length - 1]);
        length-=1;
        printReverse(string, length);
    }
}


int main()
{
    char string[100];
    gets(string);

    int length = strlen(string);

    printReverse(string, length);

    return 0;
}
