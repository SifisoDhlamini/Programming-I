#include<stdio.h>


int main()
{
    int n;
    int i, j, temp, k;
    int isPrime = 1;
    int primeFactors[99];
    int prime = 0;
    int index;
    int total;

    scanf("%d", &n);
    while (n != 0){
        temp = n;
        index = 0;
        total = 0;
        isPrime = 1;
        prime = 0;
        if (n < 4){
            break;
        } else {
            for (i = 2; i < n; i++){
                if (n % i == 0){ // check if n is a multiple of i
                    for (j = 2; j < i; j++){
                       if (i % j == 0){ //check if factor is a prime number
                            isPrime = 0;
                            break;
                       }
                    }
                    if (isPrime == 1){
                        // store prime number  in array of primeFactors[]
                        primeFactors[prime] = i;
                        prime++;
                    }
                }
            }
            // start doing prime factorization
            printf("%d = %d", n, primeFactors[index]);
            total += primeFactors[index];
            temp /=  primeFactors[index];
            while (total != n){
                if (temp % primeFactors[index] == 0){
                    temp /=  primeFactors[index];
                    total += primeFactors[index];
                    printf(" * %d", primeFactors[index]);
                } else if(temp + primeFactors[index] == total){
                    printf(" * %d", temp);
                    total += temp;
                } else {
                    index++;
                }
            }
            printf("\n");
            scanf("%d", &n);
        }
    }

    return 0;

}
