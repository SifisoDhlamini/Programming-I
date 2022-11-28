#include<stdio.h>
#include<stdbool.h>

int main(void){
    int num, i;
    bool isPrime;

    scanf("%d", &num);

    while(num != 0){
        isPrime = true;
        if (num == 1){
            isPrime = false;
        } else {
            for (i = 2; i <= num/2; i++){
                if (num % i == 0){
                    isPrime = false;
                    break;
                }
            }

        if (isPrime){
            printf("prime\n");
        } else {
                printf("not a prime\n");
            }
        }

        scanf("%d", &num);
    }

    return 0;
}
