#include<stdio.h>

int calcFactorial(int);

int main(void){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int factorial;
    factorial = calcFactorial(n);
    printf("%d is the factorial of %d", factorial, n);
}

int calcFactorial(int x){
    printf("In function n = %d\n", x);
    if (x == 0){
        return 1;
    } else {

        return x * calcFactorial(x-1);
    }
}
