#include<stdio.h>
#define N 10



int main(){

    int arr[N], i, temp, j;
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < N - 1; i++){
        for (j = i + 1; j < N; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (i = 0;i < N; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
