#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int store[99];
    int temp;
    int count = 0;
    int i;

    scanf("%d", &n);
    temp = n;

    if (n == 0){
        printf("----- ");
    } else {
        while (temp > 0){
        store[count] = temp % 10;
        temp /= 10;
        count++;
    }

        for (i = count - 1; i >= 0; i--){
            if (store[i] == 0){
                printf("----- ");
            } else if(store[i] == 1){
                printf(".---- ");
            } else if(store[i] == 2){
                printf("..--- ");
            } else if(store[i] == 3){
                printf("...-- ");
            } else if(store[i] == 4){
                printf("....- ");
            } else if(store[i] == 5){
                printf("..... ");
            } else if(store[i] == 6){
                printf("-.... ");
            } else if(store[i] == 7){
                printf("--... ");
            } else if(store[i] == 8){
                printf("---.. ");
            } else if(store[i] == 9){
                printf("----. ");
            }
        }
    }

    return 0;
}
