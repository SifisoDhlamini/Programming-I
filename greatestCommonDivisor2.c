#include<stdio.h>

int main(void){
    int a, b, c;
    int lowest;
    int i, count = 0;
    int highest = 0, highestFactor[100];

    while (scanf("%d %d %d", &a, &b, &c) != EOF){
      getchar();
        if (a > 0 && b > 0 && c > 0){
            lowest = a;
        if (b < a && b < c){
            lowest = b;
        } else if (c < a && c < b){
            lowest = c;
        }

        for (i = 1; i <= lowest; i++){
            if ((a % i == 0) && (b % i == 0) && (c % i == 0)){
                highest = i;
            }
        }
        if (highest != 0){
            highestFactor[count] = highest;
            count++;
        }
        }
        highest = 0;

    }
    if (count > 0){
        for (i = 0; i < count; i++){
            if (i == count -1){
                printf("%d", highestFactor[i]);
            } else {
                printf("%d\n", highestFactor[i]);
            }
        }
    }


    return 0;
}
