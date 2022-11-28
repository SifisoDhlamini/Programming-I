#include<stdio.h>

int main(void){
    int n, i=1;
    float half, square, lower = 0.0, upper;

    scanf("%d", &n);
    upper = (float)n;

    //do{
        for(i=1; i<=100; i++)
        {
           half = ((float)upper + (float)lower)/2.0;
        square = half * half;
        if(square >= n){
           upper = half;
        } else {
            lower = half;
        }

        }

    //} while(!((lower * lower) <= (half * half)) && ((half * half) == n && n <= (upper * upper)));

    printf("%.4f", half);
    return 0;
}
Online Judge Footer

